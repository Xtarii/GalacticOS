#ifndef GALACTIC_ISR_H
#define GALACTIC_ISR_H

#include "../../libc/ctypes.h"



extern void isr_0();
extern void isr_1();
extern void isr_2();
extern void isr_3();
extern void isr_4();
extern void isr_5();
extern void isr_6();
extern void isr_7();
extern void isr_8();
extern void isr_9();
extern void isr_10();
extern void isr_11();
extern void isr_12();
extern void isr_13();
extern void isr_14();
extern void isr_15();
extern void isr_16();
extern void isr_17();
extern void isr_18();
extern void isr_19();
extern void isr_20();
extern void isr_21();
extern void isr_22();
extern void isr_23();
extern void isr_24();
extern void isr_25();
extern void isr_26();
extern void isr_27();
extern void isr_28();
extern void isr_29();
extern void isr_30();
extern void isr_31();



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

/**
 * Interrupt service routine register handler
 */
void isr_handler(ISR_registers_t);

#endif // GALACTIC_ISR_H
