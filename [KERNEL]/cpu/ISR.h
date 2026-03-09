#ifndef GALACTIC_ISR_H
#define GALACTIC_ISR_H

#include "../utilities/types.h"

/**
 * Interrupt service routine registers
 */
typedef struct {
    /**
     * Data segment selector
     */
    uint32_t ds;

    /**
     * Pushed registers from `pusha`
     */
    uint32_t edi, esi, ebp, esp, ebx, edx, ecx, eax;

    /**
     * Interruption number
     */
    uint32_t number;
    /**
     * Interruption error code
     */
    uint32_t error;

    /**
     * Processor registers ( pushed automatically by the processor )
     */
    uint32_t eip, cs, eflags, useresp, ss;
} ISR_registers_t;



/**
 * Initializes the kernel interrupt service routine
 */
void isr_init();



void isr_handler(ISR_registers_t reg);

#endif // GALACTIC_ISR_H
