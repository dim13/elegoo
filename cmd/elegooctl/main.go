package main

import (
	"log"

	"dim13.org/elegoo"
	"github.com/tarm/serial"
)

func main() {
	conf := &serial.Config{Name: "/dev/tty.Elegoo-DevB", Baud: 38400}
	s, err := serial.OpenPort(conf)
	if err != nil {
		log.Fatal(err)
	}
	defer s.Close()
	elegoo.NewFSM(s).Start()
}
