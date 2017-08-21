package main

//go:generate sh -c "protoc --go_out=. *.proto"
//go:generate sh -c "protoc --nanopb_out=.. *.proto"

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

func main() {
	c := &serial.Config{
		Name: "/dev/tty.usbmodem1421",
		Baud: 57600,
	}
	s, err := serial.OpenPort(c)
	if err != nil {
		log.Fatal(err)
	}
	defer s.Close()

	go func() {
		time.Sleep(5 * time.Second)

		Write(s, &Command{Direction: -45})
		time.Sleep(time.Second)

		Write(s, &Command{Direction: 45})
		time.Sleep(time.Second)

		Write(s, &Command{Center: true})
	}()

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

	buf := bufio.NewReader(s)
	for {
		evt := &Event{}
		if err := Read(buf, evt); err != nil {
			log.Println("ERR", err)
		}
		log.Println(evt)
	}
}
