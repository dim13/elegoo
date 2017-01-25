package main

import (
	"io"
	"log"
	"time"

	"github.com/golang/protobuf/proto"
	"github.com/tarm/serial"
)

func Write(w io.Writer, buf []byte) {
	w.Write([]byte{byte(len(buf))})
	w.Write(buf)
}

func Read(r io.Reader) []byte {
	buf := [32]byte{}
	n, _ := r.Read(buf[:])
	return buf[:n]
	/*
		sz := [1]byte{}
		r.Read(sz[:])
		log.Println(sz)
		if l := int(sz[0]); l > 0 {
			buf := make([]byte, l)
			r.Read(buf)
			return buf
		}
		return nil
	*/
}

func varint(b []byte) []byte {
	return append([]byte{byte(len(b))}, b...)
}

// /dev/cu.Elegoo-DevB
// /dev/cu.usbmodem1421

func Wait(d time.Duration) {
	log.Println("Wait", d)
	time.Sleep(d)
}

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

	Wait(3 * time.Second)
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
			log.Printf("Got: %v", Read(s))
		}
	}()

	time.Sleep(30 * time.Second)
}
