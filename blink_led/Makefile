

build/main.o : main.c
	arm-none-eabi-gcc -O0 -c -mcpu=cortex-m4 -mthumb -std=gnu11 main.c -o build/main.o
	
build/startup.o : startup.c
	arm-none-eabi-gcc -O0 -c -mcpu=cortex-m4 -mthumb -std=gnu11 startup.c -o build/startup.o
	
main.elf : build/main.o build/startup.o
	arm-none-eabi-gcc -O0 -nostdlib -T linker.ld *.o -o build/main.elf -Wl,-Map=build/main.map

main.bin : build/main.elf
	arm-none-eabi-gcc -O0 -O binary build/main.elf build/main.bin

clean:
	rm -r build/*.o *.elf *.map