// Dimitri Sokolyuk
// 01.01.2017

#include <PacketSerial.h>
#include <Servo.h>
#include <IRremote.h>
//#include <os48.h>

#include "config.h"
#include "pb_stream.h"
#include "elegoo.pb.h"

PacketSerial serial;
Servo servo;
IRrecv irrecv(IR);

pb_istream_t istream;
pb_ostream_t ostream;

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

void move(int l, int r) {
  motor(ENA, IN1, IN2, l);
  motor(ENB, IN3, IN4, r);
}

#define forward(v)  do move( v,  v); while (0)
#define backward(v) do move(-v, -v); while (0)
#define toleft(v)   do move( v, -v); while (0)
#define toright(v)  do move(-v,  v); while (0)
#define stop()      do move( 0,  0); while (0)

int distance() {
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(18);
  digitalWrite(Trig, LOW);
  return pulseIn(Echo, HIGH, TimeOut) / ToCM;
}

void look(int deg) {
  servo.write(90 + deg);
}

#define lookahead()     do look(   0); while (0)
#define lookleft(deg)   do look( deg); while (0)
#define lookright(deg)  do look(-deg); while (0)

int ir() {
  decode_results results = {};
  if (irrecv.decode(&results)) {
    irrecv.resume();
  }
  return results.value;
}

void onPacket(const uint8_t* buf, size_t size) {
  Command cmd = Command_init_zero;

  pb_istream_t istream = pb_istream_from_buffer(buf, sizeof(buf));
  pb_decode_delimited(&istream, Command_fields, &cmd);
}

void env() {
  uint8_t buf[256];

  Event evt = Event_init_zero;

  evt.Distance = distance();
  evt.has_Distance = evt.Distance > 0;

  evt.SensorA = digitalRead(S1);
  evt.has_SensorA = true;

  evt.SensorB = digitalRead(S2);
  evt.has_SensorB = true;

  evt.SensorC = digitalRead(S3);
  evt.has_SensorC = true;

  evt.KeyPress = ir();
  evt.has_KeyPress = evt.KeyPress != 0;

  pb_ostream_t ostream = pb_ostream_from_buffer(buf, sizeof(buf));
  pb_encode_delimited(&ostream, Event_fields, &evt);

  serial.send(buf, ostream.bytes_written);
}

void loop() {
  env();
  serial.update();
}

void setup() {
  serial.begin(57600);
  serial.setPacketHandler(&onPacket);
  //pb_istream_from_stream(Serial, istream);
  //pb_ostream_from_stream(Serial, ostream);

  pinMode(Echo, INPUT);
  pinMode(Trig, OUTPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(LED, OUTPUT);

  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);

  pinMode(IR, INPUT);
  irrecv.enableIRIn();

  servo.attach(SRV);
}
