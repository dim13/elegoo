\ Fast Random Number Generator algorithm by George Marsaglia "Xorshift RNGs"

-rand
marker -rand

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
