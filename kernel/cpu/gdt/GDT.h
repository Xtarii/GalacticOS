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
#define GDT_ENTRIES 3



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
 * Sets global descriptor table entry
 */
void gdt_set(int, uint32_t, uint32_t, uint8_t, uint8_t);

/**
 * Initializes global descriptor tables
 */
void gdt_init();

#endif // _GALACTIC_GDT
