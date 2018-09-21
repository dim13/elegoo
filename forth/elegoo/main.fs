-io
marker -io \ define ports

$0023 constant PB
$0023 constant pinb
$0024 constant ddrb
$0025 constant portb

$0026 constant PC
$0026 constant pinc
$0027 constant ddrc
$0028 constant portc

$0029 constant PD
$0029 constant pind
$002a constant ddrd
$002b constant portd

-init
marker init

: bv ( bit -- mask ) 1 swap lshift ;
: pin ( bit base-addr -- ) bv swap 2dup 1+ mclr ;
: port ( bit base-addr -- ) bv swap 1+ 2dup mset 1+ ;
: set ( mask addr -- ) mset ;
: clr ( mask addr -- ) mclr ;
: init
  PB #3 port 2constant servo
  PB #5 port 2constant led
  PD #2 pin 2constant sr
  PD #3 pin 2constant sc
  PD #4 pin 2constant sl
;
: get ( mask addr -- bool ) c@ invert and 0= ;
