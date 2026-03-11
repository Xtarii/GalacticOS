global _start
[bits 32]

_start:
    [extern kernel_init]
    call kernel_init    ; C entry point
