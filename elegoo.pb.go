// Code generated by protoc-gen-go. DO NOT EDIT.
// source: elegoo.proto

/*
Package main is a generated protocol buffer package.

It is generated from these files:
	elegoo.proto

It has these top-level messages:
	Command
	Events
*/
package main

import proto "github.com/golang/protobuf/proto"
import fmt "fmt"
import math "math"

// Reference imports to suppress errors if they are not otherwise used.
var _ = proto.Marshal
var _ = fmt.Errorf
var _ = math.Inf

// This is a compile-time assertion to ensure that this generated file
// is compatible with the proto package it is being compiled against.
// A compilation error at this line likely means your copy of the
// proto package needs to be updated.
const _ = proto.ProtoPackageIsVersion2 // please upgrade the proto package

type Command struct {
	SpeedR    int32  `protobuf:"zigzag32,1,opt,name=SpeedR" json:"SpeedR,omitempty"`
	SpeedL    int32  `protobuf:"zigzag32,2,opt,name=SpeedL" json:"SpeedL,omitempty"`
	Stop      bool   `protobuf:"varint,3,opt,name=Stop" json:"Stop,omitempty"`
	Direction uint32 `protobuf:"varint,4,opt,name=Direction" json:"Direction,omitempty"`
	StopAfter uint32 `protobuf:"varint,5,opt,name=StopAfter" json:"StopAfter,omitempty"`
}

func (m *Command) Reset()                    { *m = Command{} }
func (m *Command) String() string            { return proto.CompactTextString(m) }
func (*Command) ProtoMessage()               {}
func (*Command) Descriptor() ([]byte, []int) { return fileDescriptor0, []int{0} }

func (m *Command) GetSpeedR() int32 {
	if m != nil {
		return m.SpeedR
	}
	return 0
}

func (m *Command) GetSpeedL() int32 {
	if m != nil {
		return m.SpeedL
	}
	return 0
}

func (m *Command) GetStop() bool {
	if m != nil {
		return m.Stop
	}
	return false
}

func (m *Command) GetDirection() uint32 {
	if m != nil {
		return m.Direction
	}
	return 0
}

func (m *Command) GetStopAfter() uint32 {
	if m != nil {
		return m.StopAfter
	}
	return 0
}

type Events struct {
	Distance  uint32 `protobuf:"varint,1,opt,name=Distance" json:"Distance,omitempty"`
	Direction int32  `protobuf:"zigzag32,2,opt,name=Direction" json:"Direction,omitempty"`
	SensorR   bool   `protobuf:"varint,3,opt,name=SensorR" json:"SensorR,omitempty"`
	SensorC   bool   `protobuf:"varint,4,opt,name=SensorC" json:"SensorC,omitempty"`
	SensorL   bool   `protobuf:"varint,5,opt,name=SensorL" json:"SensorL,omitempty"`
	KeyPress  uint32 `protobuf:"varint,6,opt,name=KeyPress" json:"KeyPress,omitempty"`
	Time      uint32 `protobuf:"varint,7,opt,name=Time" json:"Time,omitempty"`
}

func (m *Events) Reset()                    { *m = Events{} }
func (m *Events) String() string            { return proto.CompactTextString(m) }
func (*Events) ProtoMessage()               {}
func (*Events) Descriptor() ([]byte, []int) { return fileDescriptor0, []int{1} }

func (m *Events) GetDistance() uint32 {
	if m != nil {
		return m.Distance
	}
	return 0
}

func (m *Events) GetDirection() int32 {
	if m != nil {
		return m.Direction
	}
	return 0
}

func (m *Events) GetSensorR() bool {
	if m != nil {
		return m.SensorR
	}
	return false
}

func (m *Events) GetSensorC() bool {
	if m != nil {
		return m.SensorC
	}
	return false
}

func (m *Events) GetSensorL() bool {
	if m != nil {
		return m.SensorL
	}
	return false
}

func (m *Events) GetKeyPress() uint32 {
	if m != nil {
		return m.KeyPress
	}
	return 0
}

func (m *Events) GetTime() uint32 {
	if m != nil {
		return m.Time
	}
	return 0
}

func init() {
	proto.RegisterType((*Command)(nil), "elegoo.Command")
	proto.RegisterType((*Events)(nil), "elegoo.Events")
}

func init() { proto.RegisterFile("elegoo.proto", fileDescriptor0) }

var fileDescriptor0 = []byte{
	// 236 bytes of a gzipped FileDescriptorProto
	0x1f, 0x8b, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xff, 0x54, 0x90, 0xb1, 0x4e, 0xc3, 0x30,
	0x10, 0x86, 0x65, 0x08, 0x4e, 0x39, 0xd1, 0x01, 0x0f, 0xe8, 0x84, 0x18, 0xa2, 0x4e, 0x99, 0x58,
	0x78, 0x02, 0x48, 0x99, 0xc8, 0x80, 0x1c, 0x26, 0xb6, 0xd0, 0x1e, 0xc8, 0x12, 0xf1, 0x45, 0xb6,
	0x85, 0xc4, 0x23, 0xf0, 0x56, 0x3c, 0x1a, 0x8a, 0xdd, 0x3a, 0x61, 0xbb, 0xff, 0xff, 0x2c, 0xdd,
	0xe7, 0x83, 0x0b, 0xfa, 0xa4, 0x0f, 0xe6, 0xdb, 0xd1, 0x71, 0x60, 0x25, 0x53, 0xda, 0xfc, 0x08,
	0x28, 0x1b, 0x1e, 0x86, 0xde, 0xee, 0xd5, 0x15, 0xc8, 0x6e, 0x24, 0xda, 0x6b, 0x14, 0x95, 0xa8,
	0x2f, 0xf5, 0x21, 0xe5, 0xbe, 0xc5, 0x93, 0x45, 0xdf, 0x2a, 0x05, 0x45, 0x17, 0x78, 0xc4, 0xd3,
	0x4a, 0xd4, 0x2b, 0x1d, 0x67, 0x75, 0x03, 0xe7, 0x5b, 0xe3, 0x68, 0x17, 0x0c, 0x5b, 0x2c, 0x2a,
	0x51, 0xaf, 0xf5, 0x5c, 0x4c, 0x74, 0x7a, 0x75, 0xff, 0x1e, 0xc8, 0xe1, 0x59, 0xa2, 0xb9, 0xd8,
	0xfc, 0x0a, 0x90, 0x8f, 0x5f, 0x64, 0x83, 0x57, 0xd7, 0xb0, 0xda, 0x1a, 0x1f, 0x7a, 0xbb, 0xa3,
	0x28, 0xb3, 0xd6, 0x39, 0xff, 0x5f, 0x91, 0x8c, 0x16, 0x2b, 0x10, 0xca, 0x8e, 0xac, 0x67, 0xa7,
	0x0f, 0x5e, 0xc7, 0x38, 0x93, 0x26, 0x8a, 0x65, 0xd2, 0xcc, 0xa4, 0x8d, 0x52, 0x99, 0xb4, 0x93,
	0xc7, 0x13, 0x7d, 0x3f, 0x3b, 0xf2, 0x1e, 0x65, 0xf2, 0x38, 0xe6, 0xe9, 0xfb, 0x2f, 0x66, 0x20,
	0x2c, 0x63, 0x1f, 0xe7, 0x07, 0xf9, 0x5a, 0x0c, 0xbd, 0xb1, 0x6f, 0x32, 0x5e, 0xf9, 0xee, 0x2f,
	0x00, 0x00, 0xff, 0xff, 0x84, 0x98, 0xdf, 0xe5, 0x75, 0x01, 0x00, 0x00,
}
