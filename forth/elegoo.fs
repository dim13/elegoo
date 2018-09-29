-init
marker -init

: init ( -- )
  idle
  load+ ;

-pwm
marker -pwm

$2a constant ddrd
$44 constant tccr0a
$45 constant tccr0b
$47 constant ocr0a
$48 constant ocr0b

: timer0init
  #01100000 ddrd mset \ output PD6 PD5
  #10100011 tccr0a c! \ mode3: non-inverted pwm A and B
  #00000101 tccr0b c! \ prescale/1024
;

: setA ocr0a c! ;
: setB ocr0b c! ;

: go
  timer0init
  $1f setA
  $3f setB
;
