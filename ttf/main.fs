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

  $cb cmd! $39 byte! $2c byte! $00 byte! $34 byte! $02 byte!
  $cf cmd! $00 byte! $c1 byte! $30 byte!
  $e8 cmd! $85 byte! $00 byte! $78 byte!
  $ea cmd! $00 byte! $00 byte!
  $ed cmd! $64 byte! $03 byte! $12 byte! $81 byte!
  $f7 cmd! $20 byte!
  $c0 cmd! $23 byte!		\ power control
  $c1 cmd! $10 byte!		\ power control
  $c5 cmd! $3e byte! $28 byte!	\ vcm control
  $c7 cmd! $86 byte!		\ vcm control2
  $36 cmd! $48 byte!		\ memory access control
  $3a cmd! $55 byte!
  $b1 cmd! $00 byte! $18 byte!
  $b6 cmd! $08 byte! $82 byte! $27 byte! \ display control function
  $11 cmd! \ exit sleep
  120 ms
  $29 cmd! \ display on
  $2c cmd!
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
  begin
    320 for
      240 for
        rnd word!
      next
    next
  key? until
;
