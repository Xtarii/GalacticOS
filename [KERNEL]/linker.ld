ENTRY(_start)

SECTIONS {
    . = 0x1000;


    .text : {
        *(.text*)
    }

    .rodata : {
        *(.rodata*)
    }

    .data : {
        *(.data*)
    }

    .bss : {
        *(COMMON)
        *(.bss*)
    }


    free_memory_address = ALIGN(4096);
}
