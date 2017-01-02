#ifndef CONFIG_H
#define CONFIG_H

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

#endif
