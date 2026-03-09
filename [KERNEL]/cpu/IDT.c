#include "IDT.h"

IDT_gate_t gates[IDT_ENTRIES];
IDT_register_t reg;

void idt_gate_set(int n, uint32_t handler) {
    gates[n].low_offset = LOW_16(handler);
    gates[n].ss = KERNEL_SS;
    gates[n].p_an = 0;
    gates[n].flags = 0x8E;
    gates[n].high_offset = HIGH_16(handler);
}

void idt_set() {
    reg.base = (uint32_t)((long)&gates);
    reg.size = IDT_ENTRIES * sizeof(IDT_gate_t) - 1;
    __asm__ __volatile__("lidtl (%0)" : : "r" (&reg));
}
