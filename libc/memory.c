#include "memory.h"

void memcpy(void *src, void *dst, int bytes) {
    for(int i = 0; i < bytes; i++) {
        ((char*)dst)[i] = ((char*)src)[i];
    }
}



/**
 * Free memory address used for allocation memory
 */
extern uintptr_t free_memory_address;

uintptr_t kmalloc(size_t size, BOOL align, void * address) {
    if(align && (free_memory_address & 0xFFFFF000)) {
        free_memory_address &= 0xFFFFF000;
        free_memory_address += 0x1000;
    }

    if(address) *(uintptr_t*)(address) = free_memory_address;

    uintptr_t ret = free_memory_address;
    free_memory_address += size;
    return ret;
}
