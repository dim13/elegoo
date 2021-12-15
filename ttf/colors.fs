-colors
marker -colors

: rgb565 ( r g b -- c )
                3 rshift    swap \ blue
  %11111100 and 3 lshift or swap \ green
  %11111000 and 8 lshift or      \ red
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
