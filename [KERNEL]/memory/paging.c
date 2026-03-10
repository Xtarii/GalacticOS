#include "paging.h"
#include "memory.h"
#include <stdbool.h>
#include <stdint.h>

uint32_t *directory;

void paging_init() {
    directory = (uint32_t*)kmalloc(sizeof(uint32_t) * 1024, true, NULL);
    for(int i = 0; i < 1024; i++) directory[i] = 0x00000002;
}
