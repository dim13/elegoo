// Dimitri Sokolyuk
// 01.01.2017

//#include <PacketSerial.h>
#include <Servo.h>
#include <IRremote.h>
//#include <os48.h>

#include "config.h"
#include "pb_stream.h"
#include "elegoo.pb.h"

//PacketSerial serial;
Servo head;
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
  head.write(90 + deg);
  delay(1000); // wait to finish
}

#define lookahead()     do look(   0); while (0)
#define lookleft(deg)   do look( deg); while (0)
#define lookright(deg)  do look(-deg); while (0)

int sensor() {
  int s1 = digitalRead(S1);
  int s2 = digitalRead(S2);
  int s3 = digitalRead(S3);
  return s1 | (s2 << 1) | (s3 << 2);
}

void ultra() {
  if (distance() > dist) {
    forward(velo);
    return;
  }
  stop();
  lookleft(60);
  if (distance() > dist) {
    toleft(velo);
    lookahead();
    return;
  }
  lookright(60);
  if (distance() > dist) {
    toright(velo);
    lookahead();
    return;
  }
}

void ir() {
  decode_results results;
  if (irrecv.decode(&results)) {
    switch (results.value) {
      case KeyUp:
        forward(velo);
        break;
      case KeyDown:
        backward(velo);
        break;
      case KeyLeft:
        toleft(velo);
        break;
      case KeyRight:
        toright(velo);
        break;
      case KeyOk:
        stop();
        break;
    }
    irrecv.resume();
    delay(150);
  }
}

void setup() {
  Serial.begin(57600);
  pb_istream_from_stream(Serial, istream);
  pb_ostream_from_stream(Serial, ostream);

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

  head.attach(SRV);
  lookahead();
  stop();
}

void loop() {
  Command cmd = Command_init_zero;
  pb_decode_delimited(&istream, Command_fields, &cmd);

  Event evt = Event_init_zero;

  evt.Distance = distance();
  evt.has_Distance = evt.Distance > 0;

  evt.SensorA = digitalRead(S1);
  evt.has_SensorA = true;

  evt.SensorB = digitalRead(S2);
  evt.has_SensorB = true;

  evt.SensorC = digitalRead(S3);
  evt.has_SensorC = true;

  pb_encode_delimited(&ostream, Event_fields, &evt);

  delay(1000);
  //ultra();
  ir();
}
