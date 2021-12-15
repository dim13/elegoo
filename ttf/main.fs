-main
marker -main

: width  ( from to -- ) $2a cmd! word! word! ;
: height ( from to -- ) $2b cmd! word! word! ;
: pixels ( -- )         $2c cmd! ;

: address ( y2 y1 x2 x1 -- )
  $2a cmd! word! word!
  $2b cmd! word! word!
  $2c cmd!
;

: main
  init
  ticks seed !
;

: fill ( -- )
  320 for
    240 for
      rnd $7fff u> word!
    next
  next
;
