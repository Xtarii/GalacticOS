#include "keyboard.h"
#include "../cpu/ISR.h"
#include "../cpu/IRQ.h"
#include "../utilities/types.h"
#include "../utilities/utils.h"
#include "ports.h"
#include "screen.h"

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
