-flash-led-avr
marker -flash-led-avr
\ PB5 is Arduino digital pin 13.

$0023 constant pinb
$0024 constant ddrb
$0025 constant portb

$0026 constant pinc
$0027 constant ddrc
$0028 constant portc

$0029 constant pind
$002a constant ddrd
$002b constant portd

1 #5 lshift constant bit5

: init bit5 ddrb mset ; \ set pin as output
: do_output portb c@ bit5 xor portb c! ; \ toggle the bit
: main init begin do_output #500 ms again ;

main
