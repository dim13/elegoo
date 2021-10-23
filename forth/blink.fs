-blink
marker -blink

\ depends on ports.fs

pin5 ddrb mset

: on ( -- )
  pin5 portb mset
;

: off ( -- )
  pin5 portb mclr
;

: toggle ( -- )
  portb c@
  pin5 xor
  portb c!
;

: heart ( -- )
  begin
    on  50 ms off  50 ms
    on 100 ms off 550 ms
  key? until ;
