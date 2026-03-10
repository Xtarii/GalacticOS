#include "string.h"
#include "bool.h"

void itoa(int n, char *str) {
    bool neg = false;
    if(n < 0) {
        neg = true;
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
