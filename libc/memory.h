#ifndef MEMORY_H
#define MEMORY_H

#include "bool.h"
#include <stddef.h>
#include <stdint.h>

/**
 * Copies `n` bytes from `src` to `dst`
 */
void memcpy(void *src, void *dst, int bytes);

/**
 * Simple memory allocator
 *
 * @return Allocated memory
 */
uintptr_t kmalloc(size_t, BOOL, void*);

#endif // MEMORY_H
