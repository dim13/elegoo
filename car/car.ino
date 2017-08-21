// Dimitri Sokolyuk
// 01.01.2017

#include <PacketSerial.h>
#include <Servo.h>
#include <IRremote.h>
//#include <os48.h>

#include <pb_encode.h>
#include <pb_decode.h>

#include "elegoo.pb.h"
#include "config.h"

PacketSerial serial;
Servo servo;
int trim;

IRrecv irrecv(IR);
decode_results ir;

void motor(int e, int a, int b, int v) {
  if (v > 0) {
    digitalWrite(a, LOW);
    digitalWrite(b, HIGH);
  }
  if (v < 0) {
    digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    v = -v;
  }
  analogWrite(e, v);
}

void motorR(int v) {
  motor(ENA, IN1, IN2, v);
}

void motorL(int v) {
  motor(ENB, IN3, IN4, v);
}

int distance() {
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(18);
  digitalWrite(Trig, LOW);
  return pulseIn(Echo, HIGH, TimeOut) / ToCM;
}

// + left
// - right
void look(int deg) {
  servo.write(90 + deg + trim);
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
  if (cmd.has_Trim) {
    trim = cmd.Trim;
  }
  if (cmd.has_TurnHead) {
    look(cmd.TurnHead);
  }
  if (cmd.has_Center) {
    look(0);
  }

}

void env() {
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

  pb_ostream_t ostream = pb_ostream_from_buffer(buf, sizeof(buf));
  pb_encode_delimited(&ostream, Event_fields, &evt);

  serial.send(buf, ostream.bytes_written);
}

void loop() {
  env();
  serial.update();
  delay(200);
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
}
