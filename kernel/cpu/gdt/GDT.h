#ifndef _GALACTIC_GDT
#define _GALACTIC_GDT

#include <stdint.h>

/**
 * Flushes global descriptor table entries to the CPU
 */
extern void gdt_flush(uint32_t);

/**
 * GDT entries size
 */
#define GDT_ENTRIES 6



/**
 * Global descriptor table object
 */
typedef struct {
    /**
     * Lower limit
     */
    uint16_t lower_limit;
    /**
     * Lower base
     */
    uint16_t lower_base;
    /**
     * Middle base
     */
    uint8_t middle_base;
    /**
     * Access level
     */
    uint8_t access;
    /**
     * Granularity
     */
    uint8_t granularity;
    /**
     * Higher base
     */
    uint8_t higher_base;
} __attribute__((packed)) GDT;

/**
 * Global descriptor table pointer object
 */
typedef struct {
    /**
     * Limit
     */
    uint16_t limit;
    /**
     * Base
     */
    uint32_t base;
}  __attribute__((packed)) GDTR;



/**
 * Task state segment object
 */
typedef struct {
    /**
     * Previous TSS
     */
    uint32_t previous;
    /**
     * ESP0 register
     */
    uint32_t esp0;
    /**
     * SS0 register
     */
    uint32_t ss0;
    /**
     * ESP1 register
     */
    uint32_t esp1;
    /**
     * SS1 register
     */
    uint32_t ss1;
    /**
     * ESP2 register
     */
    uint32_t esp2;
    /**
     * SS2 register
     */
    uint32_t ss2;
    /**
     * CR3 register
     */
    uint32_t cr3;
    /**
     * EIP register
     */
    uint32_t eip;
    /**
     * TSS Flags
     */
    uint32_t eflags;
    /**
     * TSS registers
     */
    uint32_t eax, ecx, edx, ebx, esp, ebp, esi, edi;
    /**
     * TSS registers
     */
    uint32_t es, cs, ss, ds, fs, gs;
    /**
     * LDT selector
     */
    uint32_t ldt;
    /**
     * TSS trap
     */
    uint16_t trap;
    /**
     * TSS I/O map base
     */
    uint16_t base;
} __attribute__((packed)) TSS;



/**
 * Sets global descriptor table entry
 */
void gdt_set(int, uint32_t, uint32_t, uint8_t, uint8_t);

/**
 * Initializes global descriptor tables
 */
void gdt_init();

/**
 * Initializes task state segment
 */
void tss_init(uint32_t);

#endif // _GALACTIC_GDT
