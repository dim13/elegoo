package elegoo

import (
	"bufio"
	"io"
	"log"
)

type stateFn func() stateFn

type FSM struct {
	events   chan *Event
	commands chan *Command
}

func NewFSM(rw io.ReadWriter) *FSM {
	events := make(chan *Event)
	commands := make(chan *Command)
	go readEvents(rw, events)
	go writeCommands(rw, commands)
	return &FSM{events: events, commands: commands}
}

func readEvents(r io.Reader, ch chan<- *Event) {
	buf := bufio.NewReader(r)
	for {
		event := new(Event)
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
	f.commands <- &Command{Look: 0}
	return f.readDistance
}

func (f *FSM) readDistance() stateFn {
	ev := <-f.events
	log.Println(ev)
	if ev.Head.Distance < 20 {
		return f.stop
	}
	return f.moveAhead
}

func (f *FSM) moveAhead() stateFn {
	f.commands <- &Command{Speed: &Speed{L: 200, R: 200}}
	return f.readDistance
}

func (f *FSM) stop() stateFn {
	f.commands <- &Command{}
	return f.readDistance
}