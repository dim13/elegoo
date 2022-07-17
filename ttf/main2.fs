-main2
marker -main2

: xfill ( -- )
  memwr
  width for
    height for
      rnd $7fff u> word!
    next
  next
;

: cfill ( -- )
  memwr
  width for
    height for
      rnd word!
    next
  next
;
