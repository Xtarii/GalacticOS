#include "port.h"

unsigned char pbin(unsigned short port) {
    unsigned char res;
    asm("in %%dx, %%al" : "=a" (res) : "d" (port));
    return res;
}

void pbout(unsigned short port, unsigned char data) {
    asm("out %%al, %%dx"  : : "a" (data), "d" (port));
}



unsigned short pwin(unsigned short port) {
    unsigned short res;
    asm("in %%dx, %%ax" : "=a" (res) : "d" (port));
    return res;
}

void pwout(unsigned short port, unsigned short data) {
    asm("out %%ax, %%dx" : : "a" (data), "d" (port));
}
