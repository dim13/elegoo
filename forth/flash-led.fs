-flash-led-avr
marker -flash-led-avr
\ PB5 is Arduino digital pin 13.

$0023 constant pinb
$0024 constant ddrb
$0025 constant portb

1 #5 lshift constant bit5

: init bit5 ddrb mset ; \ set pin as output
: toggle portb c@ bit5 xor portb c! ; \ toggle the bit
: main init begin toggle #500 ms key? until ;

main
