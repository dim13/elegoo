#ifndef CONFIG_H
#define CONFIG_H

#define LED  13 // LED_BUILDIN

// Settings
#define dist  20
#define velo 130

// Pinout motor
#define ENA  5 // 10 pwm enable right
#define ENB  6 //  5 pwm enable left

#define IN1  7 //  9 direction backward right
#define IN2  8 //  8 direction forward  right
#define IN3  9 //  7 direction backward left
#define IN4 10 //  6 direction forward  left

// Pinout sensors
#define SR  2 // right
#define SC  4 // center
#define SL 11 // left

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

#endif
