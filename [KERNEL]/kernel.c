#include "cpu/ISR.h"
#include "drivers/screen.h"

void main() {
    isr_init();

    clear();

    __asm__ __volatile__("int $2");
    __asm__ __volatile__("int $3");

    while(1); /* Infinity loop */
}
