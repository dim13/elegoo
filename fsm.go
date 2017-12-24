package elegoo

import (
	"io"
	"log"
	"time"
)

type stateFn func() stateFn

type FSM struct {
	events   chan *Event
	commands chan *Command
	Look     int32
	Speed    *Speed
}

func NewFSM(rw io.ReadWriter) *FSM {
	events := make(chan *Event)
	commands := make(chan *Command)
	comm := NewComm(rw)
	go readEvents(comm, events)
	go writeCommands(comm, commands)
	return &FSM{events: events, commands: commands}
}

func readEvents(c ProtoComm, ch chan<- *Event) {
	for {
		event := new(Event)
		if err := c.Recv(event); err != nil {
			if err == io.ErrUnexpectedEOF {
				continue
			}
			log.Println(err)
			continue
		}
		ch <- event
	}
}

func writeCommands(c ProtoComm, ch <-chan *Command) {
	for command := range ch {
		if err := c.Send(command); err != nil {
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
	f.commands <- &Command{}
	return f.readDistance
}

func (f *FSM) readDistance() stateFn {
	ev := <-f.events
	log.Println(ev)
	if ev.Head != nil && ev.Head.Distance < 50 {
		return f.stop
	}
	return f.moveAhead
}

func (f *FSM) moveAhead() stateFn {
	f.SetSpeed(200, 200, 0)
	return f.readDistance
}

func (f *FSM) stop() stateFn {
	f.SetSpeed(0, 0, 0)
	return f.readDistance
}

func (f *FSM) SetSpeed(l, r int32, stop time.Duration) {
	f.Speed = &Speed{
		L:         l,
		R:         r,
		StopAfter: uint32(stop.Nanoseconds() / 1e6),
	}
	f.commands <- &Command{Speed: f.Speed, Look: f.Look}
}

func (f *FSM) SetDirection(dir int32) {
	f.Look = dir
	f.commands <- &Command{Speed: f.Speed, Look: f.Look}
}
