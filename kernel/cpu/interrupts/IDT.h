#ifndef _GALACTIC_IDT
#define _GALACTIC_IDT

#include <stdint.h>

/**
 * Interrupt descriptor table entries
 */
#define IDT_ENTRIES 256



/**
 * Interrupt descriptor table object
 */
typedef struct {
    /**
     * IDT lower offset
     */
    uint16_t lower_offset;
    /**
     * IDT selector
     */
    uint16_t selector;
    /**
     * Leave this always at 0
     */
    uint8_t zero;
    /**
     * IDT flags
     */
    uint8_t flags;
    /**
     * IDT higher offset
     */
    uint16_t higher_offset;
} __attribute__((packed)) IDT;

/**
 * Interrupt descriptor table pointer
 */
typedef struct {
    /**
     * Pointer limit
     */
    uint16_t limit;
    /**
     * Pointer base
     */
    uint32_t base;
} __attribute__((packed)) IDTP;



/**
 * Sets interrupt descriptor table callback
 */
void idt_set(int index, uint32_t handler, uint16_t selector, uint8_t flags);

/**
 * Initializes interrupt descriptor tables
 */
void idt_init();

#endif // _GALACTIC_IDT
