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

// Servo
#define SRV 3

// Pinout IR
#define IR 12

// Pinout Ultrasonic
#define Echo A1
#define Trig A0

#define ToCM     58
#define ToInch  148
#define TimeOut 100000

#endif
