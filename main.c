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

void delay(volatile int time) {
    while (time--);
}

int main(void) {
    RCC_AHB1ENR |=  (1 << 0);             // Enable GPIOA clock
    GPIOA_MODER |=  (1 << 10);            // Set PA5 as output
    GPIOA_MODER &=~ (1 << 11);

    while (1) {
        GPIOA_BSRR |= (1 << 5);          // Toggle PA5
    }
}
