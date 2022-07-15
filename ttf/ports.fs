-ports
marker -ports

$0023 constant  pinb
$0024 constant  ddrb
$0025 constant portb

$0026 constant  pinc
$0027 constant  ddrc
$0028 constant portc

$0029 constant  pind
$002a constant  ddrd
$002b constant portd

%00000001 portc 2constant  rdx \ A0 read at rising edge
%00000010 portc 2constant  wrx \ A1 write at rising edge
%00000100 portc 2constant d/cx \ A2 data = 1 / command = 0
%00001000 portc 2constant  csx \ A3 chip select low enable
%00010000 portc 2constant resx \ A4 active low
