#include "GDT.h"
#include <stdint.h>

/**
 * Kernel stack top ( defined in boot )
 */
extern char stack_top[];



GDT gdts[GDT_ENTRIES]; // GDT entries list
GDTR gdt_pointer;

TSS tss; // Task state segment

void gdt_set(int index, uint32_t base, uint32_t limit, uint8_t access, uint8_t gran) {
    gdts[index].lower_base = (base & 0xFFFF);
    gdts[index].middle_base = (base >> 16) & 0xFF;
    gdts[index].higher_base = (base >> 24) & 0xFF;

    gdts[index].lower_limit = (limit & 0xFFFF);
    gdts[index].granularity = (limit >> 16) & 0x0F;

    gdts[index].granularity |= gran & 0xF0;
    gdts[index].access = access;
}

void gdt_init() {
    gdt_pointer.limit = (sizeof(GDT) * GDT_ENTRIES) - 1;
    gdt_pointer.base = (uint32_t)(long)&gdts;

    // Kernel
    gdt_set(0, 0, 0, 0, 0);
    gdt_set(1, 0, 0xFFFFFFFF, 0x9A, 0xCF);
    gdt_set(2, 0, 0xFFFFFFFF, 0x92, 0xCF);

    // User
    gdt_set(3, 0, 0xFFFFFFFF, 0xFA, 0xCF);
    gdt_set(4, 0, 0xFFFFFFFF, 0xF2, 0xCF);

    // TSS
    tss_init((uint32_t)(long)stack_top);
    gdt_set(5, (uint32_t)(long)&tss, sizeof(tss) - 1, 0x89, 0x00);

    gdt_flush((uint32_t)(long)&gdt_pointer);
}

void tss_init(uint32_t stack) {
    tss.esp0 = stack;
    tss.ss0 = 0x10;
    tss.base = sizeof(TSS);
}
