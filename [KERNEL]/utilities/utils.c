#include "utils.h"

void kmemcpy(void *src, void *dst, int bytes) {
    for(int i = 0; i < bytes; i++) {
        ((char*)dst)[i] = ((char*)src)[i];
    }
}



void itoa(int n, char *buffer) {}
