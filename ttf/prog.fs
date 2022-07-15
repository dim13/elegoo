-prog
marker -prog

: width  ( from to -- ) $2a cmd! word! word! ;
: height ( from to -- ) $2b cmd! word! word! ;
: pixels ( -- )         $2c cmd! ;

: address ( y2 y1 x2 x1 -- )
  $2a cmd! word! word!
  $2b cmd! word! word!
  $2c cmd!
;

: prog
  init
  ticks seed !
;

: cfill ( -- )
  2 for
    38400 for
      rnd $7fff u> word!
    next
  next
;

: xfill ( -- )
  2 for
    38400 for
      r@ word!
    next
  next
;
