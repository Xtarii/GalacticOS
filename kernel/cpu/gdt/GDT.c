#include "GDT.h"
#include <stdint.h>

GDT gdts[GDT_ENTRIES]; // GDT entries list
GDTR pointer;

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
    pointer.limit = (sizeof(GDT) * GDT_ENTRIES) - 1;
    pointer.base = (uint32_t)(long)&gdts;

    gdt_set(0, 0, 0, 0, 0);
    gdt_set(1, 0, 0xFFFFFFFF, 0x9A, 0xCF);
    gdt_set(2, 0, 0xFFFFFFFF, 0x92, 0xCF);

    gdt_flush((uint32_t)(long)&pointer);
}
