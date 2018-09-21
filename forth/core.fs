\ Some extra core words

-core
marker -core
hex ram

\ Interpret a string. The string must be in ram
: evaluate ( caddr n -- )
  'source 2@ >r >r >in @ >r
  interpret
  r> >in ! r> r> 'source 2!
;

: forget ( --- name )
  bl word latest @ (f) ?abort?
  c>n 2- dup @ ?abort?
  dup flash dp ! @ latest ! ram
;

 ( addr n c -- ) \ fill addr to addr+n with c
: fill rot !p>r swap for dup pc! p+ next r>p drop ;

\  addr n --
: erase  0 fill ;

\ addr n --
: blanks bl fill ;

\ x -- 0 | x x
: ?dup dup if inline dup then ;

\ nfa -- flag
: in? c@ $40 and ;

\ addr -- addr+1 n 
: count c@+ ;

\ MCU with eeprom
: .free
  cr ." Flash:" flash hi here - u. ." bytes"
  cr ." Eeprom:" eeprom hi here - u. ." bytes"
  cr ." Ram:" ram hi here - u. ." bytes"
;

\ xu ... x0 u -- xu ... x0 xu
: pick 2* sp@ + @ ;

-see 
marker -see
hex ram
: *@ dup @ ;
: u.4 4 u.r ;
: *@+ dup cell+ @ u.4 ;
: 5sp 5 spaces ;
: @braddr ( addr -- addr xt-addr )
    *@ fff and dup 800 and 
    if f800 or then 2* over +  cell+ ;
: @xtaddr ( addr -- addr xt-addr )
  dup cell+ @ xa> ;
: .rjmp ( addr -- addr+2 ) @braddr u.4 cell+ ;
: .br  ( addr -- addr+2 )
     *@ 3 rshift 7f and dup 40 and 
     if ff80 or then 2* over + cell+ u.4 cell+ ;
: .reg ( addr -- addr ) 
   dup @ 4 rshift 1f and ." r" decimal 2 u.r hex cell+ ;
: .ldi ( addr -- addr )
  *@ dup 4 rshift dup 000f and 0010 + 
  ." r" decimal 2 u.r hex
  00f0 and swap 000f and + 2 u.r cell+ ;
: ?call ( addr -- addr f ) *@ fe0e and 940e - ;
: ?ret ( addr -- addr f ) *@ 9508 - ;
: ?rcall ( addr -- addr f ) *@ f000 and d000 - ;
: ?jmp  ( addr -- addr f ) *@ fe0e and 940c - ;
: ?rjmp ( addr -- addr f ) *@ f000 and c000 - ;
: ?breq ( addr --  addr f ) *@ fc07 and f001 - ;
: ?brne ( addr --  addr f ) *@ fc07 and f401 - ;
: ?brcc ( addr -- addr f ) *@ fc07 and f400 - ;
: ?pop ( addr -- addr f ) *@ fe0f and 900f - ;
: ?push ( addr -- addr f ) *@ fe0f and 920f - ;
: ?st-y ( addr -- addr f ) *@ fe0f and 920a - ;
: ?ldy+ ( addr -- addr f ) *@ fe0f and 9009 - ;
: ?ijmp ( addr -- addr f ) *@ 9409 - ;
: ?ldi ( addr -- addr f ) *@ f000 and e000 - ;
: (see) ( addr -- addr' | false )
  dup u.4
  *@ u.4
  ?call 0= if *@+ ." call  " @xtaddr c>n .id cell+ cell+ else 
  ?rcall 0= if 5sp ." rcall " @braddr c>n .id cell+ else
  ?breq 0= if 5sp ." breq  " .br else
  ?brne 0= if 5sp ." brne  " .br else
  ?brcc 0= if 5sp ." brcc  " .br else
  ?rjmp 0= if 5sp ." rjmp  " .rjmp else
  ?ijmp 0= if 5sp ." ijmp" drop false else
  ?ret  0= if 5sp ." ret"  drop false else
  ?jmp  0= if *@+ ." jmp   " @xtaddr c>n .id drop false else
  ?pop  0= if 5sp ." pop   " .reg else
  ?push 0= if 5sp ." push  " .reg else
  ?ldy+ 0= if 5sp ." ld    " .reg ." y+" else
  ?st-y 0= if 5sp ." st    -y " .reg else
  ?ldi  0= if 5sp ." ldi   " .ldi else
  cell+
  then then then then then
  then then then then then
  then then then then
  cr ;

: dis ( addr -- )
  hex cr
  begin (see) dup 0=
  until drop ;

: see ( "word" -- )  ' dis ;
hex ram

-doloop
marker -doloop

: compileonly $10 shb ;

#20 constant ind inlined   \ R18:R19 are unused by the kernel

: (do)  ( limit index -- R: leave oldindex xfaxtor ) 
  r>
  dup >a xa> @ >r            \ R: leave 
  ind @ >r                   \ R: leave oldindex
  swap $8000 swap - dup >r   \ R: leave oldindex xfactor
  + ind !
  a> 1+ >r
; compileonly

: (?do) ( limit index -- R: leave oldindex xfactor ) 
  2dup xor
  if
    [ '  (do) ] again  \ branch to (do) 
  then
  r> xa> @ >r 2drop
; compileonly

: (+loop) ( n -- )
  [ $0f48 i, ]   \ add r20, tosl
  [ $1f59 i, ]   \ add r21, tosh
  inline drop
; compileonly

: unloop
  r>
  rdrop r> ind ! rdrop
  >r
; compileonly

: do
  postpone (do)
  postpone begin
  flash 2 allot ram  \ leave address
  postpone begin
; immediate compileonly

: ?do
  postpone (?do)
  postpone begin
  flash 2 allot ram  \ leave address
  postpone begin
; immediate compileonly

: leave
  rdrop rdrop r> ind ! 
; compileonly

: i
  ind @ rp@ 3 + @ >< -
; compileonly

: j
  rp@ 5 + @ >< rp@ 9 + @ >< - 
; compileonly


: loop
  $0d46 i, $1d55 i, \ add 1 to r20:r21
\  postpone (loop)
  $f00b i,               \ bra +2 if overflow
  postpone again
  postpone unloop
  flash here >xa swap ! ram
; immediate compileonly

: +loop
  postpone (+loop)
  $f00b i,               \ bra +2 if overflow
  postpone again
  postpone unloop
  flash here >xa swap ! ram
; immediate compileonly

-bit
marker -bit
: (bio) ( c-addr -- in/out-addr ) $20 - dup $5 lshift or $60f and ;
: (bit) ( c-addr bit flag "name" -- )
  : >r
  over $40 < if
    swap $20 - 3 lshift or
    r> 
    if    $9a00   \ sbi io-addr, bit
    else  $9800   \ cbi io-addr, bit
    then  or i,
  else
    over $60 < 
    if    over (bio) $b100 or   \ in r16 io-addr
    else  $9100 i, over         \ lds r16 c-addr
    then  i, 
    1 swap lshift 
    r>
    if   $6000 >r
    else $7000 >r invert $ff and
    then dup 4 lshift or $f0f and r> or i, \ andi/ori r16, mask
    dup $60 < 
    if   (bio) $b900 or         \ out io-addr r16 
    else $9300 i,               \ sts c-addr r16
    then i,
  then 
  $9508 i,            \ return
  postpone [
;

\ Define a word that clears a bit in ram
\ The defined word can be inlined
( c-addr bit "name" -- )
: bit0: false (bit) ;

\ Define a word that sets a bit in ram
\ The defined word can be inlined
( c-addr bit "name" -- )
: bit1: true (bit) ;

\ Define a word that leaves a true flag if a bit in ram is one
\ and a false flag if a bit is zero.
\ The defined word can be inlined
( c-addr bit "name" -- )
: bit?:
  :
  $939a i, $938a i, $ef8f i, $ef9f i, \ true
  over $40 < if   
    swap $20 - 3 lshift or $9b00 or i, \  sbis io-addr, bit   
  else 
    over $60 < 
    if swap (bio) $b100 or      \ in r16 io-addr
    else $9100 i, swap          \ lds r16 c-addr
    then i, $ff00 or i,         \ sbrs r16, bit
  then
  $9601 i,            \ 1+
  $9508 i,            \ return
  postpone [
;

-task
marker -task
hex ram

\ Near definition saves memory !
: up! up ! ;
: up@ up @ ;
: op@ operator @ ;
: ul@ ulink @ ;
: ul! ulink ! ;
: op! op@ up! ;
\ access user variables of other task
: his ( task-addr var-addr -- addr )
  up@ - swap @ + 
;

\ Define a new task
\ A new task must be defined in the flash memory space
: task: ( tibsize stacksize rsize addsize -- )
  flash create 
  up@ s0 - dup          \ Basic size     ts ss rs as bs bs
  ram here + flash ,    \ User pointer   ts ss rs as bs
  4 for
    over , +
  next
  cell+                 \ Task size
  ram allot
;

\ Initialise a user area and link it to the task loop
\ May only be executed from the operator task
: tinit ( taskloop-addr task-addr -- )
  \ use task user area
  @+ up!                          \ a addsize-addr
  ul@ if                          \ ? Already running
    2drop
  else
    \ Pointer to task area
    dup 2- task ! 
    \ r0 = uarea+addsize+rsize
    @+ swap @+ rot + up@ +         \  a ssize-addr r0
    \ Save r0
    r0 !                           \  a ssize-addr
    \ s0 = r0 + ssize
    @ r0 @ + s0 !                  \  a
    \ Store task-loop address to the return stack
    r0 @ x>r                       \  rsp
    \ Store SP to return stack
    1- dup s0 @ swap !             \ rsp
    \ Store current rsp and space for saving TOS and P PAUSE
    5 - rsave !                    \ 
    \ tiu = s0 + 2
    s0 @ 2+ tiu !
    0 ul!
    0 task 2+ !        \ clear status and cr flag
    decimal            \ Set the base to decimal
  then
  op!                 \ run the operator task again
;

\ Insert a new task after operator in the linked list.
\ May only be executed from the operator task
: run ( task-addr -- )
  @ up! ul@ 0= if              \ ? Already running
    up@                        \ task-uarea
    op! ul@                    \ task-uarea operator-ulink
    over ul!      
    swap up! ul! 
  then
  op!                          \ run operator task
;

\ End a task by linking it out from the linked list
\ May only be executed from the operator task
: end ( task-addr -- )  
  @ up! ul@ if
    up@
    op!
    begin                   \ find the uarea in the linked list
      dup ul@ <>            \ uarea flag
    while
      ul@ up!               \ uarea
    repeat
    up@                     \ uarea prev-uarea
    swap up!                \ prev-uarea
    ul@                     \ prev-uarea next-uarea
    0 ul!                   \ ulink of a ended task is zero
    swap up!                \ next-uarea
    ul!                     \ 
  then
  op!
;

\ End all tasks except the operator task
\ May only be executed from the operator task
: single ( -- )
  ul@ op@ <>  if            \ Are there any running tasks 
    ul@ op@ ul!             \ link operator to himself
    up!                     \ move to next user area
    begin
      ul@ op@ <>            \ is this the last linked user area
    while
      ul@ 0 ul!             \ write zero to ulink
      up!                   \ and move to next user area
    repeat
    0 ul!
    op!
  then
;

\ List all running tasks
: tasks ( -- )
  up@ op!
  begin
    up@ 
    task @ 6 - op! c>n .id space
    up!
    ul@ op@ -
  while
    ul@ up!
  repeat
  up!
;

-io
marker -io

\ TIMER_COUNTER_1
$6f constant TIMSK1		\ Timer/Counter Interrupt Mask Register
$36 constant TIFR1		\ Timer/Counter Interrupt Flag register
$80 constant TCCR1A		\ Timer/Counter1 Control Register A
$81 constant TCCR1B		\ Timer/Counter1 Control Register B
$82 constant TCCR1C		\ Timer/Counter1 Control Register C
$84 constant TCNT1		\ Timer/Counter1  Bytes
$88 constant OCR1A		\ Timer/Counter1 Output Compare Register  Bytes
$8a constant OCR1B		\ Timer/Counter1 Output Compare Register  Bytes
$86 constant ICR1		\ Timer/Counter1 Input Capture Register  Bytes
$43 constant GTCCR		\ General Timer/Counter Control Register

\ TIMER_COUNTER_2
$70 constant TIMSK2		\ Timer/Counter Interrupt Mask register
$37 constant TIFR2		\ Timer/Counter Interrupt Flag Register
$b0 constant TCCR2A		\ Timer/Counter2 Control Register A
$b1 constant TCCR2B		\ Timer/Counter2 Control Register B
$b2 constant TCNT2		\ Timer/Counter2
$b4 constant OCR2B		\ Timer/Counter2 Output Compare Register B
$b3 constant OCR2A		\ Timer/Counter2 Output Compare Register A
$b6 constant ASSR		\ Asynchronous Status Register

\ AD_CONVERTER
$7c constant ADMUX		\ The ADC multiplexer Selection Register
$78 constant ADC		\ ADC Data Register  Bytes
$7a constant ADCSRA		\ The ADC Control and Status register A
$7b constant ADCSRB		\ The ADC Control and Status register B
$7e constant DIDR0		\ Digital Input Disable Register

\ ANALOG_COMPARATOR
$50 constant ACSR		\ Analog Comparator Control And Status Register
$7f constant DIDR1		\ Digital Input Disable Register 0x1

\ PORTB
$25 constant PORTB		\ Port B Data Register
$24 constant DDRB		\ Port B Data Direction Register
$23 constant PINB		\ Port B Input Pins

\ PORTC
$28 constant PORTC		\ Port C Data Register
$27 constant DDRC		\ Port C Data Direction Register
$26 constant PINC		\ Port C Input Pins

\ PORTD
$2b constant PORTD		\ Port D Data Register
$2a constant DDRD		\ Port D Data Direction Register
$29 constant PIND		\ Port D Input Pins

-main
marker -main
