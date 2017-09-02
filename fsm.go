package main

import (
	"bufio"
	"io"
	"log"
)

type stateFn func() stateFn

type FSM struct {
	events  chan *Events
	command chan *Command
}

func NewFSM(rw io.ReadWriter) *FSM {
	events := make(chan *Events)
	command := make(chan *Command)
	go readEvents(rw, events)
	go writeCommands(rw, command)
	return &FSM{events: events, command: command}
}

func readEvents(r io.Reader, ch chan<- *Events) {
	buf := bufio.NewReader(r)
	for {
		event := new(Events)
		if err := Recv(buf, event); err != nil {
			if err == io.ErrUnexpectedEOF {
				continue
			}
			log.Println(err)
			continue
		}
		ch <- event
	}
}

func writeCommands(w io.Writer, ch <-chan *Command) {
	for command := range ch {
		if err := Send(w, command); err != nil {
			if err == io.ErrUnexpectedEOF {
				continue
			}
			log.Println(err)
		}
	}
}

func (f *FSM) Start() {
	for state := f.initalState; state != nil; state = state() {
	}
}

func (f *FSM) initalState() stateFn {
	return nil
}
