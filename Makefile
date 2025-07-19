CC = arm-none-eabi-gcc
CFLAGS = -mcpu=cortex-m4 -mthumb -nostdlib -nostartfiles -Wall -Wextra -O0
LDSCRIPT = linker.ld

all: main.elf

main.elf: startup.s main.c linker.ld
	$(CC) $(CFLAGS) -T$(LDSCRIPT) startup.s main.c -o main.elf

flash: main.elf
	st-flash write main.elf 0x8000000

clean:
	rm -f *.elf *.bin *.hex
