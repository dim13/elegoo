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
	if err := buf.EncodeMessage(pb); err != nil {
		return err
	}
	_, err := w.Write(cobs.Encode(buf.Bytes()))
	return err
}

func Read(buf *bufio.Reader, pb proto.Message) error {
	block, err := buf.ReadBytes(0)
	if err != nil {
		return err
	}
	return proto.NewBuffer(cobs.Decode(block)).DecodeMessage(pb)
}

func Reader(r io.Reader) <-chan *Events {
	c := make(chan *Events)
	buf := bufio.NewReader(r)
	go func() {
		for {
			event := &Events{}
			if err := Read(buf, event); err != nil {
				if err == io.ErrUnexpectedEOF {
					continue
				}
				log.Println("ERR", err)
				return
			}
			log.Println("<-", event)
			c <- event
		}
	}()
	return c
}

func Writer(w io.Writer) chan<- *Command {
	c := make(chan *Command)
	go func() {
		for command := range c {
			log.Println("->", command)
			if err := Write(w, command); err != nil {
				if err == io.ErrUnexpectedEOF {
					continue
				}
				log.Println("ERR", err)
				return
			}
		}
	}()
	return c
}

func main() {
	conf := &serial.Config{
		//Name: "/dev/tty.usbmodem1421",
		//Name: "/dev/tty.usbmodem1411",
		Name: "/dev/tty.Elegoo-DevB",
		Baud: 57600,
	}
	s, err := serial.OpenPort(conf)
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

	for event := range Reader(s) {
		if event.SensorC || event.Distance < 20 {
			//w <- &Command{Stop: true}
		}
	}

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
}
