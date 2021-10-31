\ Fast Random Number Generator algorithm by George Marsaglia "Xorshift RNGs"

-rand
marker -rand

: xorshift ( n -- n )
  dup #7 lshift xor
  dup #9 rshift xor
  dup #8 lshift xor
;

variable (rnd)

: rnd ( -- n ) (rnd) @ xorshift dup (rnd) ! ;
