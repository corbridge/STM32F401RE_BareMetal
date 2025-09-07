#include <stdint.h>

#define PERIPH_BASE       0x40000000
#define AHB1_OFFSET       0x00020000
#define AHB1_BASE         (PERIPH_BASE + AHB1_OFFSET)

#define GPIOA_BASE        (AHB1_BASE + 0x0000)
#define RCC_BASE          (AHB1_BASE + 0x3800)

// RCC
#define RCC_AHB1ENR       (*(volatile unsigned int *)(RCC_BASE + 0x30))

// GPIOA
#define GPIOA_MODER       (*(volatile unsigned int *)(GPIOA_BASE + 0x00))
#define GPIOA_ODR         (*(volatile unsigned int *)(GPIOA_BASE + 0x14))
#define GPIOA_BSRR        (*(volatile unsigned int *)(GPIOA_BASE + 0x18))


int main(void) {
    RCC_AHB1ENR |=  (1 << 0);             // Enable GPIOA clock
    GPIOA_MODER |=  (1 << 10);           // Set PA5 as output
    GPIOA_MODER &= ~(1 << 11); 

    GPIOA_MODER &= ~((3 << 10) | (3 << 12)); // Clear mode bits for PA5 & PA6
    GPIOA_MODER |=  ((1 << 10) | (1 << 12)); // Set PA5 & PA6 to output mode

    while (1) {
        GPIOA_ODR |= (1 << 6);          // Toggle PA5
        GPIOA_ODR |= (1 << 5); 
        for (volatile uint32_t i = 0; i < 500000; i++);
        GPIOA_ODR &=~ (1 << 5); 
        GPIOA_ODR &=~ (1 << 6); 
        for (volatile uint32_t i = 0; i < 500000; i++);

        // for(uint32_t i = 0; i < 10000000000; i++){;}
        // GPIOA_ODR &=~ (1 << 5);          // Toggle PA5
        // for(uint32_t i = 0; i < 10000000000; i++){;}
    }
}
