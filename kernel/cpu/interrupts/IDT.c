#include "IDT.h"
#include <stdint.h>

IDT idts[IDT_ENTRIES];
IDTP idt_pointer;

void idt_set(int index, uint32_t handler, uint16_t selector, uint8_t flags) {
    idts[index].lower_offset = (uint16_t)((handler) & 0xFFFF);
    idts[index].selector = selector;
    idts[index].zero = 0;
    idts[index].flags = flags;
    idts[index].higher_offset = (uint16_t)(((handler) >> 16) & 0xFFFF);
}

void idt_init() {
    idt_pointer.base = (uint32_t)(long)&idts;
    idt_pointer.limit = IDT_ENTRIES * sizeof(IDT) - 1;
    asm volatile("lidtl (%0)" : : "r" (&idt_pointer));
}
