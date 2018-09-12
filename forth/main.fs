-io
marker -io \ define ports

$23 constant pinb
$24 constant ddrb
$25 constant portb

$26 constant pinc
$27 constant ddrc
$28 constant portc

$29 constant pind
$2a constant ddrd
$2b constant portd

: bv ( bit -- mask ) 1 swap lshift ;

#5 bv portb 2constant led
#5 bv ddrb mset

#2 bv pind 2constant sr
#2 bv ddrd mclr

#4 bv pind 2constant sc
#4 bv ddrd mclr

#3 bv pind 2constant sl
#3 bv ddrd mclr

: read ( mask port -- flag )
  c@ invert 0= swap drop ;
