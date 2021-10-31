-main
marker -main

: init ( -- )
  %00011111 ddrc  mset \ output
  %00011111 portc mset \ pull high

  resx mset  5 ms
  resx mclr 15 ms
  resx mset 15 ms
  csx mset
  wrx mset
  csx mclr

  $cb cmd! $39 byte! $2c byte! $00 byte! $34 byte! $02 byte!	\ Power control A
  $cf cmd! $00 byte! $c1 byte! $30 byte!			\ Power control B
  $e8 cmd! $85 byte! $00 byte! $78 byte!			\ Driver timing control A
  $ea cmd! $00 byte! $00 byte!					\ Driver timing control B
  $ed cmd! $64 byte! $03 byte! $12 byte! $81 byte!		\ Power on sequence control
  $f7 cmd! $20 byte!						\ Pump ratio control
  $c0 cmd! $23 byte!						\ Power Control 1
  $c1 cmd! $10 byte!						\ Power Control 2
  $c5 cmd! $3e byte! $28 byte!					\ VCOM Control 1
  $c7 cmd! $86 byte!						\ VCOM Control 2
  $36 cmd! $48 byte!						\ Memory Access Control
  $3a cmd! $55 byte!						\ COLMOD: Pixel Format Set
  $b1 cmd! $00 byte! $18 byte!					\ Frame Rate Control
  $b6 cmd! $08 byte! $82 byte! $27 byte!			\ Display Function Control
  $11 cmd!							\ Sleep Out
  120 ms
  $29 cmd!							\ Display ON
  $2c cmd!							\ Memory Write
;

: width  ( from to -- len ) $2a cmd! word! word! ;
: height ( from to -- len ) $2b cmd! word! word! ;
: pixels ( -- )             $2c cmd! ;


: address ( y2 y1 x2 x1 -- )
  $2a cmd! word! word!
  $2b cmd! word! word!
  $2c cmd!
;

: main
  init
  ticks is (rnd)
  320 for
    240 for
      rnd $7fff u> word!
    next
  next
;
