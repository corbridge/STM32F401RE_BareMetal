.syntax unified
.thumb

.section .isr_vector, "a", %progbits
.type _estack, %object
.word   _estack          // Initial stack pointer
.word   Reset_Handler    // Reset handler

.section .text
.global Reset_Handler
.type Reset_Handler, %function

Reset_Handler:
    // Zero initialize the .bss section
    ldr r0, =_sbss        // Start address of .bss
    ldr r1, =_ebss        // End address of .bss
    movs r2, #0           // Zero to fill

bss_loop:
    cmp r0, r1
    bge bss_done
    str r2, [r0]
    adds r0, r0, #4
    b bss_loop

bss_done:
    bl main               // Call main()
    b .                   // Trap if main returns

.size Reset_Handler, . - Reset_Handler
