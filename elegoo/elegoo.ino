// Dimitri Sokolyuk
// 01.01.2017

#include <PacketSerial.h>
#include <Servo.h>
#include <Timer.h>
#include <IRremote.h>

#include <pb_encode.h>
#include <pb_decode.h>

#include "elegoo.pb.h"
#include "config.h"

PacketSerial serial;
Servo servo;
Timer timer;
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

int readDistance() {
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(18);
  digitalWrite(Trig, LOW);
  return pulseIn(Echo, HIGH, TimeOut) / ToCM;
}

void stop() {
  motorR(0);
  motorL(0);
}

void onPacket(const uint8_t* buf, size_t size) {
  elegoo_Command cmd = elegoo_Command_init_zero;

  pb_istream_t istream = pb_istream_from_buffer(buf, size);
  pb_decode_delimited(&istream, elegoo_Command_fields, &cmd);

  if (cmd.Speed.R > 0) {
    motorR(cmd.Speed.R);
  }
  if (cmd.Speed.L > 0) {
    motorL(cmd.Speed.L);
  }
  if (cmd.Stop) {
    stop();
  }
  if (cmd.Direction > 0) {
    servo.write(cmd.Direction);
  }
  if (cmd.StopAfter > 0) {
    timer.after(cmd.StopAfter, stop);
  }
}

void events() {
  uint8_t buf[64];

  elegoo_Events evt = elegoo_Events_init_zero;

  evt.Distance = readDistance();
  evt.Sensor.R = digitalRead(SR);
  evt.Sensor.C = digitalRead(SC);
  evt.Sensor.L = digitalRead(SL);

  if (irrecv.decode(&ir)) {
    evt.KeyPress = ir.value;
    irrecv.resume();
  }

  evt.Direction = servo.read();
  evt.Time = millis();

  pb_ostream_t ostream = pb_ostream_from_buffer(buf, sizeof(buf));
  pb_encode_delimited(&ostream, elegoo_Events_fields, &evt);

  serial.send(buf, ostream.bytes_written);
}

void loop() {
  timer.update();
  serial.update();
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

  timer.every(100, events);
  timer.oscillate(LED, 500, LOW);
}
