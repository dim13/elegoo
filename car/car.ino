// Dimitri Sokolyuk
// 01.01.2017

#include <Servo.h>
#include <IRremote.h>

// Settings
#define dist  20
#define velo 130

// Pinout motor
#define ENA  5 // 10 pwm
#define ENB  6 // 5  pwm

#define IN1  7 // 9
#define IN2  8 // 8
#define IN3  9 // 7
#define IN4 10 // 6

// Pinout sensors
#define S1  2
#define S2  4
#define S3 11

// Pinout IR
#define IR 12

#define KeyUp     0x00511DBB
#define KeyDown   0xA3C8EDDB
#define KeyLeft   0x52A3D41F
#define KeyRight  0x20FE4DBB
#define KeyOk     0xD7E84B1B
#define Key0      0x1BC0157B
#define Key1      0xC101E57B
#define Key2      0x97483BFB
#define Key3      0xF0C41643
#define Key4      0x9716BE3F
#define Key5      0x3D9AE3F7
#define Key6      0x6182021B
#define Key7      0x8C22657B
#define Key8      0x488F3CBB
#define Key9      0x0449E79F
#define KeyStar   0x97483BFB


// Pinout Ultrasonic
#define Echo A1
#define Trig A0

#define ToCM     58
#define ToInch  148
#define TimeOut 100000

Servo head;
IRrecv irrecv(IR);

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
  Serial.begin(9600);

  pinMode(Echo, INPUT);
  pinMode(Trig, OUTPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);

  pinMode(IR, INPUT);
  irrecv.enableIRIn();

  head.attach(3);
  lookahead();
  stop();
}

void loop() {
  //ultra();
  ir();
}

