-pile
marker -pile

\ "no weighting" from starting forth chapter 12
variable density
variable theta
variable id

: " ( -- addr )   [char] " word dup c@ 1+ allot ;

: material ( addr n1 n2 -- )    \ addr=string, n1=density, n2=theta
   create  , , , 
   does> ( -- )   dup @ theta !
   cell+ dup @ density !  cell+ @ id ! ;

: .substance ( -- )   id @ count type ;
: foot ( n1 -- n2 )   10 * ;
: inch ( n1 -- n2 )   100 12 */  5 +  10 /  + ;
: /tan ( n1 -- n2 )   1000 theta @ */ ;

: pile ( n -- )         \ n=scaled height
   dup dup 10 */ 1000 */  355 339 */  /tan /tan
   density @ 200 */  ." = " . ." tons of "  .substance ;

\ table of materials
\   string-address  density  tan[theta] 
   " cement"           131        700  material cement
   " loose gravel"      93        649  material loose-gravel
   " packed gravel"    100        700  material packed-gravel
   " dry sand"          90        754  material dry-sand
   " wet sand"         118        900  material wet-sand
   " clay"             120        727  material clay
