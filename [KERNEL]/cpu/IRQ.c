#include "IRQ.h"
#include "IDT.h"
#include "ISR.h"
#include "../drivers/ports.h"

isr_t handlers[INTERRUPT_HANDLERS];

void irq_init() {
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

    idt_gate_set(IRQ0, (uint32_t)(long)irq_0);
    idt_gate_set(IRQ1, (uint32_t)(long)irq_1);
    idt_gate_set(IRQ2, (uint32_t)(long)irq_2);
    idt_gate_set(IRQ3, (uint32_t)(long)irq_3);
    idt_gate_set(IRQ4, (uint32_t)(long)irq_4);
    idt_gate_set(IRQ5, (uint32_t)(long)irq_5);
    idt_gate_set(IRQ6, (uint32_t)(long)irq_6);
    idt_gate_set(IRQ7, (uint32_t)(long)irq_7);
    idt_gate_set(IRQ8, (uint32_t)(long)irq_8);
    idt_gate_set(IRQ9, (uint32_t)(long)irq_9);
    idt_gate_set(IRQ10, (uint32_t)(long)irq_10);
    idt_gate_set(IRQ11, (uint32_t)(long)irq_11);
    idt_gate_set(IRQ12, (uint32_t)(long)irq_12);
    idt_gate_set(IRQ13, (uint32_t)(long)irq_13);
    idt_gate_set(IRQ14, (uint32_t)(long)irq_14);
    idt_gate_set(IRQ15, (uint32_t)(long)irq_15);
}

void register_irq(uint8_t n, isr_t handler) {
    handlers[n] = handler;
}

void irq_handler(ISR_registers_t reg) {
    if(reg.number >= 40) pbout(0xA0, 0x20);
    pbout(0x20, 0x20);

    if(handlers[reg.number] != 0) {
        isr_t handler = handlers[reg.number];
        handler(reg);
    }
}
