package main

//go:generate sh -c "protoc --go_out=. --nanopb_out=elegoo/ *.proto"

import (
	"bufio"
	"io"
	"log"

	"github.com/dim13/cobs"
	"github.com/golang/protobuf/proto"
	"github.com/tarm/serial"
)

func Send(w io.Writer, pb proto.Message) error {
	buf := new(proto.Buffer)
	if err := buf.EncodeMessage(pb); err != nil {
		return err
	}
	_, err := w.Write(cobs.Encode(buf.Bytes()))
	return err
}

func Recv(buf *bufio.Reader, pb proto.Message) error {
	block, err := buf.ReadBytes(0)
	if err != nil {
		return err
	}
	return proto.NewBuffer(cobs.Decode(block)).DecodeMessage(pb)
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

	NewFSM(s).Start()
}
