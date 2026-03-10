#include "memory.h"
#include <stdint.h>

/**
 * Free memory address used for allocation memory
 *
 * This is provided by the linker.
 */
extern uintptr_t free_memory_address;



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
