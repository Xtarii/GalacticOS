#ifndef GALACTIC_IRQ_H
#define GALACTIC_IRQ_H

#include "ISR.h"
#include "../../libc/ctypes.h"

/**
 * Number of interrupt handlers
 *
 * This is the number of registered
 * interrupt handlers.
 *
 * Note that this can not be changed.
 */
#define INTERRUPT_HANDLERS 256



extern void irq_0();
extern void irq_1();
extern void irq_2();
extern void irq_3();
extern void irq_4();
extern void irq_5();
extern void irq_6();
extern void irq_7();
extern void irq_8();
extern void irq_9();
extern void irq_10();
extern void irq_11();
extern void irq_12();
extern void irq_13();
extern void irq_14();
extern void irq_15();

#define IRQ0 32
#define IRQ1 33
#define IRQ2 34
#define IRQ3 35
#define IRQ4 36
#define IRQ5 37
#define IRQ6 38
#define IRQ7 39
#define IRQ8 40
#define IRQ9 41
#define IRQ10 42
#define IRQ11 43
#define IRQ12 44
#define IRQ13 45
#define IRQ14 46
#define IRQ15 47



/**
 * Interrupt handler callback function
 */
typedef void (*isr_t)(ISR_registers_t);

/**
 * Initializes the kernel interrupt requests
 */
void irq_init();

/**
 * Registers interrupt request callback
 */
void register_irq(uint8_t, isr_t);

/**
 * Interrupt request handler
 */
void irq_handler(ISR_registers_t);

#endif // GALACTIC_IRQ_H
