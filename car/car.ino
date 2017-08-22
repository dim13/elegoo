// Dimitri Sokolyuk
// 01.01.2017

#include <PacketSerial.h>
#include <Servo.h>
#include <IRremote.h>

#include <pb_encode.h>
#include <pb_decode.h>

#include "elegoo.pb.h"
#include "config.h"

PacketSerial serial;
Servo servo;

IRrecv irrecv(IR);
decode_results ir;

void motor(int e, int a, int b, int v) {
  if (v == 0) {
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
  } else if (v > 0) {
    digitalWrite(a, LOW);
    digitalWrite(b, HIGH);
  } else if (v < 0) {
    digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    v = -v;
  }
  analogWrite(e, v);
}

#define motorR(v) motor(ENA, IN1, IN2, v)
#define motorL(v) motor(ENB, IN3, IN4, v)
#define look(deg) servo.write(deg + 90)
#define looking() (servo.read() - 90)

int distance() {
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(18);
  digitalWrite(Trig, LOW);
  return pulseIn(Echo, HIGH, TimeOut) / ToCM;
}

void onPacket(const uint8_t* buf, size_t size) {
  Command cmd = Command_init_zero;

  pb_istream_t istream = pb_istream_from_buffer(buf, size);
  pb_decode_delimited(&istream, Command_fields, &cmd);

  if (cmd.has_SpeedR) {
    motorR(cmd.SpeedR);
  }
  if (cmd.has_SpeedL) {
    motorL(cmd.SpeedL);
  }
  if (cmd.has_Stop) {
    motorR(0);
    motorL(0);
  }
  if (cmd.has_Direction) {
    look(cmd.Direction);
  }
  if (cmd.has_Center) {
    look(0);
  }
}

void events() {
  uint8_t buf[256];

  Event evt = Event_init_zero;

  evt.Distance = distance();
  evt.has_Distance = evt.Distance > 0;

  evt.SensorR = digitalRead(SR);
  evt.has_SensorR = true;

  evt.SensorC = digitalRead(SC);
  evt.has_SensorC = true;

  evt.SensorL = digitalRead(SL);
  evt.has_SensorL = true;

  if (irrecv.decode(&ir)) {
    evt.KeyPress = ir.value;
    evt.has_KeyPress = ir.bits > 0;
    irrecv.resume();
  }

  evt.Direction = looking();
  evt.has_Direction = true;

  pb_ostream_t ostream = pb_ostream_from_buffer(buf, sizeof(buf));
  pb_encode_delimited(&ostream, Event_fields, &evt);

  serial.send(buf, ostream.bytes_written);
}

void loop() {
  events();
  serial.update();
  delay(100);
}

void setup() {
  serial.begin(57600);
  serial.setPacketHandler(&onPacket);

  pinMode(Echo, INPUT);
  pinMode(Trig, OUTPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(LED, OUTPUT);

  pinMode(SR, INPUT);
  pinMode(SC, INPUT);
  pinMode(SL, INPUT);

  pinMode(IR, INPUT);
  irrecv.enableIRIn();

  servo.attach(SRV);
  servo.write(90);
}
