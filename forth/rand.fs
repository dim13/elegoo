\ Fast Random Number Generator algorithm by George Marsaglia "Xorshift RNGs"

-rnd
marker -rnd

: xorshift ( n -- n )
  dup #13 lshift xor
  dup #17 rshift xor
  dup #5  lshift xor
;

variable (rnd)	\ seed
ticks (rnd) !	\ initialize seed

: rnd ( -- n )
  (rnd) @ xorshift dup (rnd) !
;
