package main

//go:generate sh -c "protoc --go_out=. --nanopb_out=elegoo/ *.proto"

import (
	"bufio"
	"io"
	"log"
	"time"

	"github.com/dim13/cobs"
	"github.com/golang/protobuf/proto"
	"github.com/tarm/serial"
)

func Write(w io.Writer, pb proto.Message) error {
	buf := new(proto.Buffer)
	err := buf.EncodeMessage(pb)
	if err != nil {
		return err
	}
	block := cobs.Encode(buf.Bytes())
	_, err = w.Write(block)
	return err
}

func Read(buf *bufio.Reader, pb proto.Message) error {
	block, err := buf.ReadBytes(0)
	if err != nil {
		return err
	}
	block = cobs.Decode(block)
	return proto.NewBuffer(block).DecodeMessage(pb)
}

// /dev/cu.Elegoo-DevB
// /dev/cu.usbmodem1421
// /dev/cu.usbmodem1411

func Reader(r io.Reader) chan *Events {
	c := make(chan *Events)
	buf := bufio.NewReader(r)
	go func() {
		for {
			e := &Events{}
			if err := Read(buf, e); err != nil {
				if err == io.ErrUnexpectedEOF {
					continue
				}
				log.Println("ERR", err)
				return
			}
			log.Println("<-", e)
			c <- e
		}
	}()
	return c
}

func Writer(w io.Writer) chan *Command {
	c := make(chan *Command)
	go func() {
		for cmd := range c {
			log.Println("->", cmd)
			Write(w, cmd)
		}
	}()
	return c
}

func main() {
	c := &serial.Config{
		//Name: "/dev/tty.usbmodem1421",
		//Name: "/dev/tty.usbmodem1411",
		Name: "/dev/tty.Elegoo-DevB",
		Baud: 57600,
	}
	s, err := serial.OpenPort(c)
	if err != nil {
		log.Fatal(err)
	}
	defer s.Close()

	w := Writer(s)

	go func() {
		for i := 30; i < 140; i += 10 {
			w <- &Command{Direction: uint32(i)}
			time.Sleep(100 * time.Millisecond)
		}
		for i := 140; i > 30; i -= 10 {
			w <- &Command{Direction: uint32(i)}
			time.Sleep(100 * time.Millisecond)
		}
		w <- &Command{Direction: 85}
	}()

	for e := range Reader(s) {
		if e.SensorC || e.Distance < 20 {
			//w <- &Command{Stop: true}
		}
	}

	/* log.Println("send -45")
	time.Sleep(3 * time.Second)
	Write(s, &Command{Direction: 5})

	log.Println("send +45")
	time.Sleep(3 * time.Second)
	Write(s, &Command{Direction: 175})

	log.Println("send +0")
	time.Sleep(3 * time.Second)
	Write(s, &Command{Direction: 90})
	*/

	/* log.Println("send motor")
	Write(s, &Command{SpeedL: 200, SpeedR: 200, StopAfter: 1000})
	time.Sleep(time.Second)

	log.Println("send motor turn")
	time.Sleep(time.Second)
	Write(s, &Command{SpeedL: -250, SpeedR: 250, StopAfter: 500})

	log.Println("send motor turn")
	time.Sleep(time.Second)
	Write(s, &Command{SpeedL: 250, SpeedR: -250, StopAfter: 500})
	*/

	/* MOTOR
	cmd.SpeedL = 200
	cmd.SpeedR = 0
	cmd.Stop = false
	Write(s, cmd)
	time.Sleep(3 * time.Second)

	cmd.SpeedL = 0
	cmd.SpeedR = 0
	cmd.Stop = true
	Write(s, cmd)
	time.Sleep(3 * time.Second)

	cmd.SpeedL = 0
	cmd.SpeedR = 200
	cmd.Stop = false
	Write(s, cmd)
	time.Sleep(3 * time.Second)

	cmd.SpeedL = 0
	cmd.SpeedR = 0
	cmd.Stop = true
	Write(s, cmd)
	*/
}
