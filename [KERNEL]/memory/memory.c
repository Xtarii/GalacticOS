#include "memory.h"
#include <stdint.h>

/**
 * Kernel end address
 */
extern char kernel_end_address;

/**
 * Free memory address used for allocation memory
 *
 * This is provided by the linker.
 */
uintptr_t free_memory_address;

void memory_init() {
    free_memory_address = (uintptr_t)&kernel_end_address;
}



uintptr_t kmalloc(size_t size, bool align, uintptr_t *address) {
    if(align && (free_memory_address & 0xFFFFF000)) {
        free_memory_address &= 0xFFFFF000;
        free_memory_address += 0x1000;
    }

    if(address) *address = free_memory_address;

    uintptr_t ret = free_memory_address;
    free_memory_address += size;
    return ret;
}
