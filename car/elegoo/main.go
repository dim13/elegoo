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

func Write(w io.Writer, buf []byte) {
	sz := proto.EncodeVarint(uint64(len(buf)))
	w.Write(append(sz, buf...))
}

func Read(r io.Reader) []byte {
	buf := make([]byte, 1)
	r.Read(buf)
	sz, _ := proto.DecodeVarint(buf)
	nbuf := make([]byte, int(sz))
	io.ReadFull(r, nbuf)
	return nbuf
}

func varint(b []byte) []byte {
	return append([]byte{byte(len(b))}, b...)
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

	cmd := &Command{
		SetSpeed: &Speed{
			Left:  100,
			Right: 120,
		},
	}
	buf, err := proto.Marshal(cmd)
	if err != nil {
		log.Fatal(err)
	}
	log.Printf("Send: %x", buf)
	//Write(s, buf)

	go func() {
		for {
			buf := Read(s)
			log.Printf("Got: %x", buf)
			evt := &Event{}
			proto.Unmarshal(buf, evt)
			log.Println(evt)
		}
	}()

	time.Sleep(time.Minute)
}
