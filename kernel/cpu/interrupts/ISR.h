#ifndef _GALACTIC_ISR
#define _GALACTIC_ISR

#include<stdint.h>

//
// External handlers for process interruptions
//

extern void isr_divide_by_zero(void);

//
// \\------------------------------//
//



/**
 * Interrupt service register object
 */
typedef struct {
    /**
     * Data segment register
     */
    uint32_t ds;
    /**
     * Data pushed by `pusha`
     */
    uint32_t edi, esi, ebp, esp, ebx, edx, ecx, eax;
    /**
     * Interrupt code
     */
    uint32_t code;
    /**
     * Error code
     */
    uint32_t error;

    /**
     * Processor values
     *
     * These are pushed by the processor automatically.
     */
    uint32_t eip, cs, flags, useresp, ss;
} ISR;



/**
 * Interrupt service route handler callback
 */
typedef void (*isr_func)(ISR);



/**
 * Initializes the interruption service
 */
void isr_init(void);

/**
 * Registers an interruption callback handler to the interrupt service
 */
void isr_register(uint8_t, isr_func);



void isr_handler(ISR isr);

#endif // _GALACTIC_ISR
