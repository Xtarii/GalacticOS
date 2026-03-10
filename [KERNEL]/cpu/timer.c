#include "timer.h"
#include "IRQ.h"
#include "ISR.h"
#include "../drivers/ports.h"
#include "../drivers/screen.h"
#include "../../libc/string.h"

uint32_t tick = 0;

static void callback(ISR_registers_t reg) {
    tick++;

    kprint_at("Tick: ", 0, 0);
    char ascii[256];
    itoa(tick, ascii);
    kprint(ascii);
    kprint("\n");
}



void init_timer(uint32_t freq) {
    register_irq(IRQ0, callback);

    uint32_t divisor = 1193180 / freq;
    uint8_t low = (uint8_t)(divisor & 0xFF);
    uint8_t high = (uint8_t)((divisor >> 8) & 0xFF);

    pbout(0x43, 0x36);
    pbout(0x40, low);
    pbout(0x40, high);
}
