#include "string.h"
#include "bool.h"
#include <stdint.h>

void itoa(int n, char *str) {
    BOOL neg = FALSE;
    if(n < 0) {
        neg = TRUE;
        n = -n;
    }

    int i = 0;
    do {
        str[i++] = n % 10 + '0';
    }while((n /= 10) > 0);

    if(neg) str[i++] = '-';
    str[i] = '\0';
    reverse(str);
}

void htoa(int n, char *str) {
    str[0] = '0';
    str[1] = 'x';
    char zeros = 0;

    int32_t tmp;
    int i, c = 2;
    for(i = 28; i > 0; i -= 4) {
        tmp = (n >> i) & 0xF;
        if(tmp == 0 && zeros == 0) continue;
        zeros = 1;
        if(tmp > 0xA) str[c++] = tmp - 0xA + 'A';
        else str[c++] = tmp + '0';
    }

    tmp = n & 0xF;
    if(tmp >= 0xA) str[c++] = tmp - 0xA + 'A';
    else str[c++] = tmp + '0';
}

void reverse(char *str) {
    char c;
    for(int i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        c = str[i];
        str[i] = str[j];
        str[j] = c;
    }
}

int strlen(const char *str) {
    int len = 0;
    while(str[len++]);
    return len - 1;
}

int strcmp(const char *a, const char *b) {
    int i;
    for(i = 0; a[i] == b[i]; i++) { if(a[i] == '\0') return 0; }
    return a[i] - b[i];
}
