#include "cpu/IRQ.h"
#include "cpu/ISR.h"
// #include "cpu/timer.h"
// #include "drivers/keyboard.h"
#include "drivers/screen.h"

#include "../libc/string.h"

void kernel_main() {
    irq_init();
    isr_init();
    asm volatile("sti"); // Needed for callbacks

    // clear();

    char ascii[5];
    htoa(0xFF, ascii);
    kprint(ascii);
    kprint("\n");

    // init_timer(1193180 * 2);

    // init_keyboard();

    while(1); /* Infinity loop */
}
