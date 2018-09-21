-uno
marker -uno

\ USART0
$c6 constant UDR0		\ USART I/O Data Register
$c0 constant UCSR0A		\ USART Control and Status Register A
$c1 constant UCSR0B		\ USART Control and Status Register B
$c2 constant UCSR0C		\ USART Control and Status Register C
$c4 constant UBRR0		\ USART Baud Rate Register  Bytes

\ TWI
$bd constant TWAMR		\ TWI (Slave) Address Mask Register
$b8 constant TWBR		\ TWI Bit Rate register
$bc constant TWCR		\ TWI Control Register
$b9 constant TWSR		\ TWI Status Register
$bb constant TWDR		\ TWI Data register
$ba constant TWAR		\ TWI (Slave) Address register

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

\ TIMER_COUNTER_0
$48 constant OCR0B		\ Timer/Counter0 Output Compare Register
$47 constant OCR0A		\ Timer/Counter0 Output Compare Register
$46 constant TCNT0		\ Timer/Counter0
$45 constant TCCR0B		\ Timer/Counter Control Register B
$44 constant TCCR0A		\ Timer/Counter  Control Register A
$6e constant TIMSK0		\ Timer/Counter0 Interrupt Mask Register
$35 constant TIFR0		\ Timer/Counter0 Interrupt Flag register

\ EXTERNAL_INTERRUPT
$69 constant EICRA		\ External Interrupt Control Register
$3d constant EIMSK		\ External Interrupt Mask Register
$3c constant EIFR		\ External Interrupt Flag Register
$68 constant PCICR		\ Pin Change Interrupt Control Register
$6d constant PCMSK2		\ Pin Change Mask Register 0x2
$6c constant PCMSK1		\ Pin Change Mask Register 0x1
$6b constant PCMSK0		\ Pin Change Mask Register 0x0
$3b constant PCIFR		\ Pin Change Interrupt Flag Register

\ SPI
$4e constant SPDR		\ SPI Data Register
$4d constant SPSR		\ SPI Status Register
$4c constant SPCR		\ SPI Control Register

\ WATCHDOG
$60 constant WDTCSR		\ Watchdog Timer Control Register

\ CPU
$64 constant PRR		\ Power Reduction Register
$66 constant OSCCAL		\ Oscillator Calibration Value
$61 constant CLKPR		\ Clock Prescale Register
$5F constant SREG		\ Status Register
$5d constant SP			\ Stack Pointer 
$57 constant SPMCSR		\ Store Program Memory Control and Status Register
$55 constant MCUCR		\ MCU Control Register
$54 constant MCUSR		\ MCU Status Register
$53 constant SMCR		\ Sleep Mode Control Register
$4b constant GPIOR2		\ General Purpose I/O Register 0x2
$4a constant GPIOR1		\ General Purpose I/O Register 0x1
$3e constant GPIOR0		\ General Purpose I/O Register 0x0

\ EEPROM
$41 constant EEAR		\ EEPROM Address Register  Bytes
$40 constant EEDR		\ EEPROM Data Register
$3f constant EECR		\ EEPROM Control Register

\ Interrupts
$02 constant INT0Addr		\ External Interrupt Request 0x0
$04 constant INT1Addr		\ External Interrupt Request 0x1
$06 constant PCINT0Addr		\ Pin Change Interrupt Request 0x0
$08 constant PCINT1Addr		\ Pin Change Interrupt Request 0x0
$0a constant PCINT2Addr		\ Pin Change Interrupt Request 0x1
$0c constant WDTAddr		\ Watchdog Time-out Interrupt
$0e constant TIMER2_COMPAAddr	\ Timer/Counter2 Compare Match A
$10 constant TIMER2_COMPBAddr	\ Timer/Counter2 Compare Match A
$12 constant TIMER2_OVFAddr	\ Timer/Counter2 Overflow
$14 constant TIMER1_CAPTAddr	\ Timer/Counter1 Capture Event
$16 constant TIMER1_COMPAAddr	\ Timer/Counter1 Compare Match A
$18 constant TIMER1_COMPBAddr	\ Timer/Counter1 Compare Match B
$1a constant TIMER1_OVFAddr	\ Timer/Counter1 Overflow
$1c constant TIMER0_COMPAAddr	\ TimerCounter0 Compare Match A
$1e constant TIMER0_COMPBAddr	\ TimerCounter0 Compare Match B
$20 constant TIMER0_OVFAddr	\ Timer/Couner0 Overflow
$22 constant SPI_STCAddr	\ SPI Serial Transfer Complete
$24 constant USART_RXAddr	\ USART Rx Complete
$26 constant USART_UDREAddr	\ USART, Data Register Empty
$28 constant USART_TXAddr	\ USART Tx Complete
$2a constant ADCAddr		\ ADC Conversion Complete
$2c constant EE_READYAddr	\ EEPROM Ready
$2e constant ANALOG_COMPAddr	\ Analog Comparator
$30 constant TWIAddr		\ Two-wire Serial Interface
$32 constant SPM_ReadyAddr	\ Store Program Memory Read
