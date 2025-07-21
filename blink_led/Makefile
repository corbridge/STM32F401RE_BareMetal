

main.o : main.c
	arm-none-eabi-gcc -c -mcpu=cortex-m4 -mthumb -std=gnu11 main.c -o main.o
	
startup.o : startup.c
	arm-none-eabi-gcc -c -mcpu=cortex-m4 -mthumb -std=gnu11 startup.c -o startup.o
	
main.elf : main.o startup.o
	arm-none-eabi-gcc -nostdlib -T linker.ld *.o -o main.elf -Wl,-Map=main.map

main.bin : main.elf
	arm-none-eabi-objcopy -O binary main.elf main.bin

clean:
	del	-f *.o *.elf *.map