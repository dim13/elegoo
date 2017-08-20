package main

//go:generate sh -c "protoc --go_out=. *.proto"
//go:generate sh -c "protoc --nanopb_out=.. *.proto"

import (
	"io"
	"log"
	"time"

	"github.com/golang/protobuf/proto"
	"github.com/tarm/serial"
)

func Write(w io.Writer, pb proto.Message) error {
	buf := new(proto.Buffer)
	err := buf.EncodeMessage(pb)
	if err != nil {
		return err
	}
	_, err = w.Write(buf.Bytes())
	return err
}

func Read(r io.Reader, pb proto.Message) error {
	buf := make([]byte, 80)
	n, err := r.Read(buf)
	if err != nil {
		return err
	}
	log.Prinltn("got: % x", buf[:n]) // DEBUG
	return proto.NewBuffer(buf[:n]).DecodeMessage(pb)
}

// /dev/cu.Elegoo-DevB
// /dev/cu.usbmodem1421

func main() {
	c := &serial.Config{
		Name: "/dev/cu.usbmodem1421",
		Baud: 57600,
	}
	s, err := serial.OpenPort(c)
	if err != nil {
		log.Fatal(err)
	}
	defer s.Close()

	cmd := &Command{}
	Write(s, cmd)

	go func() {
		for {
			evt := &Event{}
			Read(s, evt)
			log.Println(evt)
		}
	}()

	time.Sleep(time.Minute)
}
