#include "keyboard.h"
#include "../cpu/ISR.h"
#include "../cpu/IRQ.h"
#include "ports.h"
#include "screen.h"

#include "../../libc/string.h"
#include "../../libc/ctypes.h"

static void callback(ISR_registers_t reg) {
    uint8_t code = pbin(0x60);
    char ascii[256];
    itoa(code, ascii);
    kprint("Keyboard: ");
    kprint(ascii);
    kprint("\n");
}

void init_keyboard() {
    register_irq(IRQ1, callback);
}
