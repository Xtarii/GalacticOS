#ifndef GALACTIC_IDT_H
#define GALACTIC_IDT_H

#include <stdint.h>

/**
 * Kernel segment selectors
 */
#define KERNEL_SS 0x08

/**
 * Low 16 bit for address
 */
#define LOW_16(address) (uint16_t)((address) & 0xFFFF)
/**
 * High 16 bit for address
 */
#define HIGH_16(address) (uint16_t)(((address) >> 16) & 0xFFFF)

/**
 * Interrupt descriptor gate structure
 */
typedef struct {
    /**
     * Lower byte of handler function address
     */
    uint16_t low_offset;
    /**
     * Kernel segment selector
     */
    uint16_t ss;

    /**
     * Private value. Should always be set to `0`
     */
    uint8_t p_an;

    /**
     * 8 byte flag
     *
     * | Bit(s) |                                                  |
     * |--------|--------------------------------------------------|
     * |  7     | Interrupt is present                             |
     * | 6-5    | Privilege level of caller (0 = kernel, 3 = user) |
     * | 4      | Set to 0 for interrupt gate                      |
     * | 3-0    | Bits 1110 = decimal, 14 = "32 bit interrupt gate |
     */
    uint8_t flags;

    /**
     * Higher byte of handler function address
     */
    uint16_t high_offset;

} __attribute__((packed)) IDT_gate_t;

/**
 * Interrupt descriptor register structure
 *
 * A pointer to an array of interrupt handlers.
 */
typedef struct {
    /**
     * Array size
     */
    uint16_t size;
    /**
     * Array starting point
     */
    uint32_t base;
} __attribute__((packed)) IDT_register_t;



/**
 * Interrupt descriptor entries
 *
 * This is the number of gates to store.
 * It can not be changed or overwritten.
 */
#define IDT_ENTRIES 256


/**
 * Sets interrupt descriptor gate
 *
 * @param n Gate number
 * @param handler Gate handler address
 */
void idt_gate_set(int n, uint32_t handler);

/**
 * Sets interrupt descriptor
 */
void idt_set();

#endif // GALACTIC_IDT_H
