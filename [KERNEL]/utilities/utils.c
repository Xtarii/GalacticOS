#include "utils.h"

void kmemcpy(void *src, void *dst, int bytes) {
    for(int i = 0; i < bytes; i++) {
        ((char*)dst)[i] = ((char*)src)[i];
    }
}



int numlen(int n) {
    int len = 0;
    if(n < 0) n = -n;
    do len++; while((n /= 10) > 0);
    return len;
}



void itoa(int n, char *buffer) {
    int o = 0;
    if(n < 0) {
        n = -n;
        buffer[o++] = '-';
    }

    int len = numlen(n);
    for(int i = len - 1; i >= 0; i--) {
        int p = i + o;
        buffer[p] = n % 10 + '0';
        n /= 10;
    }
}
