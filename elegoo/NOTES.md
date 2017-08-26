Pinout
------

Trig = A0	orange
Echo = A1	red


ENA = 10	green		left
IN1 = 9		blue
IN2 = 8		brown

IN3 = 7		gray		right
IN4 = 6		white
ENB = 5		black


>>>
	ENA 5	green
	ENB 6	black
	IN1 7	blue
	IN2 8	brown
	IN3 9	gray
	IN4 10	white
<<<

Servo = 3

S1 = 2
S2 = 4
S3 = 11

IR = 12

Protocol
--------

int16: bigEndian

Motor speed: int16, range -255 .. 255 left and right

	<XX> <LL> <LL> <RR> <RR>

Head position: int8 degree, range 0 .. 180

	<XX> <DD>

Distance reading event: uint16, centimeter

	<XX> <DD> <DD>

Sensor change event:

	<XX> <SS>
