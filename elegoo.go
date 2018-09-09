package elegoo

import (
	"bufio"
	"io"

	"github.com/dim13/cobs"
	"github.com/golang/protobuf/proto"
)

//go:generate sh -c "protoc --go_out=. --nanopb_out=elegoo/ *.proto"

type ProtoComm interface {
	Send(pb proto.Message) error
	Recv(pb proto.Message) error
}

type Comm struct {
	w *bufio.Writer
	r *bufio.Reader
}

func NewComm(rw io.ReadWriter) Comm {
	return Comm{w: bufio.NewWriter(rw), r: bufio.NewReader(rw)}
}

func (c Comm) Send(msg proto.Message) error {
	buf := proto.NewBuffer(nil)
	if err := buf.EncodeMessage(msg); err != nil {
		return err
	}
	if _, err := c.w.Write(cobs.Encode(buf.Bytes())); err != nil {
		return err
	}
	return c.w.Flush()
}

func (c Comm) Recv(msg proto.Message) error {
	block, err := c.r.ReadBytes(0)
	if err != nil {
		return err
	}
	buf := proto.NewBuffer(cobs.Decode(block))
	return buf.DecodeMessage(msg)
}
