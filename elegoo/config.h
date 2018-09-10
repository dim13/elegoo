#ifndef CONFIG_H
#define CONFIG_H

#define LED  13 // LED_BUILDIN 			PB5 Out

// Settings
#define dist  20
#define velo 130

// Pinout motor
#define ENA  5 // 10 pwm enable right		PD5 Out PWM
#define ENB  6 //  5 pwm enable left		PD6 Out PWM

#define IN1  7 //  9 direction backward right	PD7 Out
#define IN2  8 //  8 direction forward  right	PB0 Out
#define IN3  9 //  7 direction backward left	PB1 Out
#define IN4 10 //  6 direction forward  left	PB2 Out

// Pinout sensors
#define SR  2 // right				PD2 In
#define SC  4 // center				PD4 In
#define SL 11 // left				PB3 In

// Servo
#define SRV 3 //				PD3 Out PWM

// Pinout IR
#define IR 12 //				PB4 In

// Pinout Ultrasonic
#define Echo A1 //				PC1 In
#define Trig A0 //				PC0 Out

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
