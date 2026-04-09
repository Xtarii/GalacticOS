[extern isr_handler]

;
; Common ISR assembly handler
;
isr_common:
    pusha
    mov ax, ds
    push eax
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    call isr_handler

    pop eax
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    popa
    add esp, 8
    sti
    iret





global isr_divide_by_zero
isr_divide_by_zero:
    cli
    push byte 0
    push byte 0
    jmp isr_common
