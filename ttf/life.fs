: gen ( c n -- c ) or 3 = ;

\ population count
: popcnt ( n -- u )
  0 swap
  begin dup
  while tuck 1 and + swap 1 rshift
  repeat drop
;
