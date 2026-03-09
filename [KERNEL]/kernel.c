#include "cpu/ISR.h"
#include "drivers/screen.h"
#include "utilities/utils.h"

void main() {
    isr_init();

    clear();



    char s[15];
    itoa(15, s);
    kprint(s);
    kprint("\n\n");



    __asm__ __volatile__("int $2");
    __asm__ __volatile__("int $3");

    while(1); /* Infinity loop */
}
