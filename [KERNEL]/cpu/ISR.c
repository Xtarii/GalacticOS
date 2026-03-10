#include "ISR.h"
#include "IDT.h"
#include "../drivers/screen.h"
#include "../../libc/string.h"

void isr_init() {
    idt_gate_set(0, (uint32_t)(long)isr_0);
    idt_gate_set(1, (uint32_t)(long)isr_1);
    idt_gate_set(2, (uint32_t)(long)isr_2);
    idt_gate_set(3, (uint32_t)(long)isr_3);
    idt_gate_set(4, (uint32_t)(long)isr_4);
    idt_gate_set(5, (uint32_t)(long)isr_5);
    idt_gate_set(6, (uint32_t)(long)isr_6);
    idt_gate_set(7, (uint32_t)(long)isr_7);
    idt_gate_set(8, (uint32_t)(long)isr_8);
    idt_gate_set(9, (uint32_t)(long)isr_9);
    idt_gate_set(10, (uint32_t)(long)isr_10);
    idt_gate_set(11, (uint32_t)(long)isr_11);
    idt_gate_set(12, (uint32_t)(long)isr_12);
    idt_gate_set(13, (uint32_t)(long)isr_13);
    idt_gate_set(14, (uint32_t)(long)isr_14);
    idt_gate_set(15, (uint32_t)(long)isr_15);
    idt_gate_set(16, (uint32_t)(long)isr_16);
    idt_gate_set(17, (uint32_t)(long)isr_17);
    idt_gate_set(18, (uint32_t)(long)isr_18);
    idt_gate_set(19, (uint32_t)(long)isr_19);
    idt_gate_set(20, (uint32_t)(long)isr_20);
    idt_gate_set(21, (uint32_t)(long)isr_21);
    idt_gate_set(22, (uint32_t)(long)isr_22);
    idt_gate_set(23, (uint32_t)(long)isr_23);
    idt_gate_set(24, (uint32_t)(long)isr_24);
    idt_gate_set(25, (uint32_t)(long)isr_25);
    idt_gate_set(26, (uint32_t)(long)isr_26);
    idt_gate_set(27, (uint32_t)(long)isr_27);
    idt_gate_set(28, (uint32_t)(long)isr_28);
    idt_gate_set(29, (uint32_t)(long)isr_29);
    idt_gate_set(30, (uint32_t)(long)isr_30);
    idt_gate_set(31, (uint32_t)(long)isr_31);

    idt_set(); // Loads handles with assembly
    asm volatile("sti"); // Needed for callbacks
}


char *messages[] = {
    "Division by zero",
    "Debug",
    "Non maskable interrupt",
    "Breakpoint",
    "Into detected overflow",
    "Out of bounds",
    "Invalid opcode",
    "No coprocessor",

    "Double fault",
    "Coprocessor segment overrun",
    "Bad tss",
    "Segment not present",
    "Stack fault",
    "General protection fault",
    "Page fault",
    "Unkown interrupt",

    "Coprocessor fault",
    "Alignment check",
    "Machine check",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",

    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
};



void isr_handler(ISR_registers_t *reg) {
    kprint("Received interrupt: ");
    char s[3];
    itoa(reg->number, s);
    kprint(s);
    kprint("\n");
    kprint(messages[reg->number]);
    kprint("\n");
}
