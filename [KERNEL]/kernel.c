#include "cpu/IRQ.h"
#include "cpu/ISR.h"
#include "cpu/timer.h"
#include "drivers/keyboard.h"
#include "drivers/screen.h"

void main() {
    irq_init();
    isr_init();

    clear();

    asm volatile("sti");
    init_timer(50);

    init_keyboard();

    while(1); /* Infinity loop */
}
