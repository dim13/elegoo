-colors
marker -colors

: rgb565 ( r g b -- c )
                3 rshift    swap \ blue
  %11111100 and 3 lshift or swap \ green
  %11111000 and 8 lshift or      \ red
;

$00 $00 $00 rgb565 constant black   \ 0
$ff $00 $00 rgb565 constant red     \ 1
$00 $ff $00 rgb565 constant green   \ 2
$ff $ff $00 rgb565 constant yellow  \ 3
$00 $00 $ff rgb565 constant blue    \ 4
$ff $00 $ff rgb565 constant magenta \ 5
$00 $ff $ff rgb565 constant cyan    \ 6
$ff $ff $ff rgb565 constant white   \ 7
