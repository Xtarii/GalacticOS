#ifndef GALACTIC_MEMORY_H
#define GALACTIC_MEMORY_H

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

/**
 * Kernel system method for allocating memory
 *
 * @return The allocated memory address
 */
uintptr_t kmalloc(size_t, bool, uintptr_t*);

#endif // GALACTIC_MEMORY_H
