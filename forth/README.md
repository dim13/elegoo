# http://flashforth.com/

see git@github.com:oh2aun/flashforth.git

# flash chip:

Using USBasp

```
/Applications/Arduino.app/Contents/Java/hardware/tools/avr/bin/avrdude \
       -C/Applications/Arduino.app/Contents/Java/hardware/tools/avr/etc/avrdude.conf \
       -v -p m328p -c usbasp -e -u \
       -Uflash:w:firmware/328-16MHz-38400.hex:i \
       -Uefuse:w:0x07:m -Uhfuse:w:0xda:m -Ulfuse:w:0xff:m
```

Using AVR as ISP

```
/Applications/Arduino.app/Contents/Java/hardware/tools/avr/bin/avrdude \
       -C/Applications/Arduino.app/Contents/Java/hardware/tools/avr/etc/avrdude.conf \
       -v -p m328p -c avrisp -P /dev/cu.usbmodem1101 -b 19200 -e -u \
       -Uflash:w:firmware/328-16MHz-38400.hex:i \
       -Uefuse:w:0x07:m -Uhfuse:w:0xda:m -Ulfuse:w:0xff:m
```

# baud rate

38400
