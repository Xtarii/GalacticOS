#include "ISR.h"
#include "IDT.h"
#include "../../drivers/port.h"

/// ISR callback handlers
isr_func handlers[256];



void isr_init(void) {
    void set(int num, uint32_t handler);

    set(0, (uint32_t)(long)isr_divide_by_zero);

    // Remapping PIC
    pbout(0x20, 0x11);
    pbout(0xA0, 0x11);
    pbout(0x21, 0x20);
    pbout(0xA1, 0x28);
    pbout(0x21, 0x04);
    pbout(0xA1, 0x02);
    pbout(0x21, 0x01);
    pbout(0xA1, 0x01);
    pbout(0x21, 0x0);
    pbout(0xA1, 0x0);
}

void isr_register(uint8_t x, isr_func func) {}

void isr_handler(ISR isr) {}





void set(int num, uint32_t handler) {
    idt_set(num, handler, 0x08, 0x8E);
}
