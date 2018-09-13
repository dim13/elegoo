-io
marker -io \ define ports

$23 constant pinb
$24 constant ddb
$25 constant portb

$26 constant pinc
$27 constant ddc
$28 constant portc

$29 constant pind
$2a constant ddd
$2b constant portd

: bv ( bit -- mask ) 1 swap lshift ;

#5 bv portb 2constant led
#5 bv ddb mset

#2 bv pind 2constant sr
#2 bv ddd mclr

#4 bv pind 2constant sc
#4 bv ddd mclr

#3 bv pind 2constant sl
#3 bv ddd mclr

-main
marker -main

: read ( mask port -- flag )
  c@ invert and 0= nip ;
