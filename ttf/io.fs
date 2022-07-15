-i/o
marker -i/o

: strobe ( port -- ) 2dup mclr mset ;

: wr ( c -- )
  %11111100 ddrd   mset
  %00000011 ddrb   mset
  dup
  %11111100 and    portd c@
  %00000011 and or portd c! \ bit[7:2]
  %00000011 and    portb c@
  %11111100 and or portb c! \ bit[1:0]
  wrx strobe
;

: rd ( -- c )
  %11111100 ddrd mclr
  %00000011 ddrb mclr
  rdx strobe
  pind c@ %11111100 and
  pinb c@ %00000011 and or
;

: command  ( -- ) d/cx mclr ;
: data     ( -- ) d/cx mset ;

: cmd!  ( c -- ) command wr ;
: byte! ( c -- ) data    wr ;
: byte@ ( -- c ) data    rd ;

: word! ( w -- )
  dup
  #8 rshift byte! \ hi
  $ff and byte!   \ lo
;

\ : id ( -- x x x x ) $04 cmd! byte@ byte@ byte@ byte@ ;
