#include "ISR.h"
#include "IDT.h"

void isr_init(void) {
    void set(int num, uint32_t handler);

    set(0, (uint32_t)(long)isr_divide_by_zero);
}

void isr_handler(ISR isr) {}





void set(int num, uint32_t handler) {
    idt_set(num, handler, 0x08, 0x8E);
}
