-core
marker -core

\ Interpret a string. The string must be in ram
: evaluate ( caddr n -- )
  'source 2@ >r >r >in @ >r
  interpret
  r> >in ! r> r> 'source 2!
;

: forget ( --- name )
  bl word latest @ (f) ?abort?
  c>n 2- dup @ ?abort?
  dup flash dp ! @ latest ! ram
;

\ fill addr to addr+n with c
: fill ( addr n c -- ) rot !p>r swap for dup pc! p+ next r>p drop ;
: erase ( addr n -- ) 0 fill ;
: blanks ( addr n -- ) bl fill ;
: ?dup ( x -- 0 | x x ) dup if inline dup then ;
: in?  ( nfa -- flag ) c@ $40 and ;
: count ( addr -- addr+1 n ) c@+ ;

variable seed

: xorshift ( n -- n )
  dup #7 lshift xor
  dup #9 rshift xor
  dup #8 lshift xor
;

: rnd  ( -- n )
  seed @
  xorshift
  dup seed !
;

$23 constant  pinb
$24 constant  ddrb
$25 constant portb
$26 constant  pinc
$27 constant  ddrc
$28 constant portc
$29 constant  pind
$2a constant  ddrd
$2b constant portd

%00000001 portc 2constant  rdx \ A0 read at rising edge
%00000010 portc 2constant  wrx \ A1 write at rising edge
%00000100 portc 2constant d/cx \ A2 data = 1 / command = 0
%00001000 portc 2constant  csx \ A3 chip select low enable
%00010000 portc 2constant resx \ A4 active low
%11111100 constant himask
%00000011 constant lomask

: cmd    ( -- ) d/cx mclr ;
: data   ( -- ) d/cx mset ;
: strobe ( mask port -- ) 2dup mclr mset ;
: wrdir  ( -- ) himask ddrd mset lomask ddrb mset ;
: rddir  ( -- ) himask ddrd mclr lomask ddrb mclr ;

: wr ( c -- )
  dup
  himask and portd c@ lomask and or portd c! \ bit[7:2]
  lomask and portb c@ himask and or portb c! \ bit[1:0]
  wrx strobe
;

: rd ( -- c )
  rdx mclr
  himask pind c@ and lomask pinb c@ and or
  rdx mset
;

: word! ( w -- )
  dup
  #8 rshift wr \ hi
  $ff and wr   \ lo
;

: reg@ ( cmd -- ) wrdir cmd wr rddir data ;
: reg! ( cmd -- ) wrdir cmd wr data ;

: id4 ( -- version model )
  $d3 reg@ rd rd rd rd
  swap 8 lshift or
  rot drop
;

#320 constant width
#240 constant height

: reset ( -- )
  %00011111  ddrc mset \ output
  %00011111 portc mset \ pull high

  resx mset  #5 ms
  resx mclr #15 ms
  resx mset #15 ms
  csx  mset
  wrx  mset
  csx  mclr

  $cb reg! $39 wr $2c wr $00 wr $34 wr $02 wr	\ Power control A
  $cf reg! $00 wr $c1 wr $30 wr			\ Power control B
  $e8 reg! $85 wr $00 wr $78 wr			\ Driver timing control A
  $ea reg! $00 wr $00 wr			\ Driver timing control B
  $ed reg! $64 wr $03 wr $12 wr $81 wr		\ Power on sequence control
  $f7 reg! $20 wr				\ Pump ratio control
  $c0 reg! $23 wr				\ Power Control 1
  $c1 reg! $10 wr				\ Power Control 2
  $c5 reg! $3e wr $28 wr			\ VCOM Control 1
  $c7 reg! $86 wr				\ VCOM Control 2
  $36 reg! $48 wr				\ Memory Access Control
  $3a reg! $55 wr				\ COLMOD: Pixel Format Set
  $b1 reg! $00 wr $18 wr			\ Frame Rate Control
  $b6 reg! $08 wr $82 wr $27 wr			\ Display Function Control
  $11 reg!					\ Sleep Out
  #120 ms
  $29 reg!					\ Display On

  ticks seed !
;

: memwr ( -- ) $2c reg! ; \ memory write

: rgb565 ( r g b -- c )
                #3 rshift    swap \ blue
  %11111100 and #3 lshift or swap \ green
  %11111000 and #8 lshift or      \ red
;

$00 $00 $00 rgb565 constant black
$80 $00 $00 rgb565 constant maroon
$00 $80 $00 rgb565 constant green
$80 $80 $00 rgb565 constant olive
$00 $00 $80 rgb565 constant navy
$80 $00 $80 rgb565 constant purple
$00 $80 $80 rgb565 constant teal
$c0 $c0 $c0 rgb565 constant silver
$80 $80 $80 rgb565 constant gray
$ff $00 $00 rgb565 constant red
$00 $ff $00 rgb565 constant lime
$ff $ff $00 rgb565 constant yellow
$00 $00 $ff rgb565 constant blue
$ff $00 $ff rgb565 constant fuchsia
$00 $ff $ff rgb565 constant aqua
$ff $ff $ff rgb565 constant white
