package elegoo

import (
	"bufio"
	"io"

	"github.com/dim13/cobs"
	"github.com/golang/protobuf/proto"
)

//go:generate sh -c "protoc --go_out=. --nanopb_out=firmware/ *.proto"

func Send(w io.Writer, pb proto.Message) error {
	buf := new(proto.Buffer)
	if err := buf.EncodeMessage(pb); err != nil {
		return err
	}
	_, err := w.Write(cobs.Encode(buf.Bytes()))
	return err
}

func RecvR(r io.Reader, pb proto.Message) error {
	block, err := bufio.NewReader(r).ReadBytes(0)
	if err != nil {
		return err
	}
	return proto.NewBuffer(cobs.Decode(block)).DecodeMessage(pb)
}

func Recv(buf *bufio.Reader, pb proto.Message) error {
	block, err := buf.ReadBytes(0)
	if err != nil {
		return err
	}
	return proto.NewBuffer(cobs.Decode(block)).DecodeMessage(pb)
}
