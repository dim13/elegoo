# http://flashforth.com/

git@github.com:oh2aun/flashforth.git

# flash chip:

/Applications/Arduino.app/Contents/Java/hardware/tools/avr/bin/avrdude \
       -C/Applications/Arduino.app/Contents/Java/hardware/tools/avr/etc/avrdude.conf \
       -v -p m328p -c avrisp -P /dev/cu.usbmodem1411 -b 19200 -e -u \
       -Uflash:w:ff_uno.hex:i -Uefuse:w:0x07:m -Uhfuse:w:0xda:m -Ulfuse:w:0xff:

# baud rate

9600
