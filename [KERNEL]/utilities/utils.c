#include "utils.h"

void kmemcpy(void *src, void *dst, int bytes) {
    for(int i = 0; i < bytes; i++) {
        ((char*)dst)[i] = ((char*)src)[i];
    }
}



void itoa(int n, char *buffer) {
    int i = 0, sign = 0;
    if((sign = n) < 0) n = -n;
    do {
        buffer[i++] = n % 10 + '0';
    }while((n /= 10) > 0);

    if(sign < 10) buffer[i++] = '-';
    buffer[i] = '\0';
}
