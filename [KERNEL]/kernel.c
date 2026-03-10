#include "cpu/IRQ.h"
#include "cpu/ISR.h"
// #include "cpu/timer.h"
// #include "drivers/keyboard.h"
#include "drivers/screen.h"

#include "../libc/string.h"
#include "memory/memory.h"

void kernel_main() {
    irq_init();
    isr_init();
    asm volatile("sti"); // Needed for callbacks

    // clear();

    uintptr_t addr;
    uintptr_t mem = kmalloc(1000, true, &addr);


    char page_str[16] = "";
    htoa(mem, page_str);
    char phys_str[16] = "";
    htoa(addr, phys_str);

    kprint("Page: ");
    kprint(page_str);

    kprint(", physical address: ");
    kprint(phys_str);

    kprint("\n");


    // init_timer(1193180 * 2);

    // init_keyboard();

    while(1); /* Infinity loop */
}
