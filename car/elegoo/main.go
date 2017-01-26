package main

import (
	"io"
	"log"
	"time"

	"github.com/golang/protobuf/proto"
	"github.com/tarm/serial"
)

func Write(w io.Writer, buf []byte) {
	sz := proto.EncodeVarint(uint64(len(buf)))
	w.Write(sz)
	w.Write(buf)
}

func Read(r io.Reader) []byte {
	buf := [10]byte{}
	r.Read(buf[:])
	sz, n := proto.DecodeVarint(buf[:])

	nbuf := make([]byte, int(sz))

	copy(nbuf, buf[int(n):])

	if int(sz) > int(10-n) {
		io.ReadFull(r, nbuf[int(10-n):])
	}
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
	log.Printf("Send: %v", buf)
	Write(s, buf)

	go func() {
		for {
			buf := Read(s)
			log.Printf("Got: %v", buf)
			evt := &Event{}
			proto.Unmarshal(buf, evt)
			log.Println(evt)
		}
	}()

	time.Sleep(30 * time.Second)
}
