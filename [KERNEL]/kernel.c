#include "cpu/IRQ.h"
#include "cpu/ISR.h"
// #include "cpu/timer.h"
// #include "drivers/keyboard.h"
#include "drivers/screen.h"

// #include "../libc/string.h"
#include "memory/memory.h"
#include "memory/paging.h"

extern void kernel_main(void);
extern char stack_start;
extern char STACK_SIZE;

void kernel_init(void) {
    irq_init();
    isr_init();
    memory_init();
    paging_init();



    uint32_t addr = (uint32_t)(long)kernel_main;
    addr += 0xC0000000;
    void (*higher_main)() = (void*)addr;
    higher_main();
}



void kernel_main(void) {
    kprint("Entered higher-half kernel\n");

    while(1); /* Infinity loop */
}
