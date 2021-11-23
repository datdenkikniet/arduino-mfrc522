F_CPU=16000000
MCU=atmega328p

ifeq (${TTY},)
TTY:=/dev/ttyUSB0
endif

target/hex: target/elf
	avr-objcopy -O ihex target/elf target/hex

target/elf: target src/main.c src/usart.h src/usart.c
	avr-gcc -Os -mmcu=${MCU} -DF_CPU=16000000 -o target/elf src/main.c src/usart.h src/usart.c

flash: target/hex
	avrdude -p atmega328p -U flash:w:target/hex:i -c arduino -P ${TTY} -b 57600

attach:
	picocom -q -b 38400 ${TTY}

flash-and-attach: flash attach

target:
	mkdir -p target/

clean:
	rm -rf target/*
