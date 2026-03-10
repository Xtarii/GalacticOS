#include "paging.h"
#include "memory.h"
#include <stdbool.h>
#include <stdint.h>

/**
 * External page enabler ( ASM )
 */
extern void enable_paging(uint32_t*);



/**
 * Paging directory
 */
uint32_t *directory;

uint32_t *first_table;

void paging_init() {
    directory = (uint32_t*)kmalloc(sizeof(uint32_t) * 1024, true, NULL);
    for(int i = 0; i < 1024; i++) directory[i] = 0x00000002;

    first_table = (uint32_t*)kmalloc(sizeof(uint32_t) * 1024, true, NULL);
    for(unsigned int i = 0; i < 1024; i++) first_table[i] = (i * 0x1000) | 3;
    directory[0] = ((unsigned int)first_table | 3);

    enable_paging(directory);
}
