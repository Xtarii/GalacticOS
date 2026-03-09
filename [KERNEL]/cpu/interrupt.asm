[extern isr_handler]

isr:
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



global isr_0
global isr_1
global isr_2
global isr_3
global isr_4
global isr_5
global isr_6
global isr_7
global isr_8
global isr_9
global isr_10
global isr_11
global isr_12
global isr_13
global isr_14
global isr_15
global isr_16
global isr_17
global isr_18
global isr_19
global isr_20
global isr_21
global isr_22
global isr_23
global isr_24
global isr_25
global isr_26
global isr_27
global isr_28
global isr_29
global isr_30
global isr_31



isr_0:
    cli
    push byte 0
    push byte 0
    jmp isr

isr_1:
    cli
    push byte 0
    push byte 1
    jmp isr

isr_2:
    cli
    push byte 0
    push byte 2
    jmp isr

isr_3:
    cli
    push byte 0
    push byte 3
    jmp isr

isr_4:
    cli
    push byte 0
    push byte 4
    jmp isr

isr_5:
    cli
    push byte 0
    push byte 5
    jmp isr

isr_6
    cli
    push byte 0
    push byte 6
    jmp isr

isr_7:
    cli
    push byte 0
    push byte 7
    jmp isr

isr_8:
    cli
    push byte 8
    jmp isr

isr_9:
    cli
    push byte 0
    push byte 9
    jmp isr

isr_10:
    cli
    push byte 10
    jmp isr

isr_11:
    cli
    push byte 11
    jmp isr

isr_12:
    cli
    push byte 12
    jmp isr

isr_13:
    cli
    push byte 13
    jmp isr

isr_14:
    cli
    push byte 14
    jmp isr

isr_15:
    cli
    push byte 0
    push byte 15
    jmp isr

isr_16:
    cli
    push byte 0
    push byte 16
    jmp isr

isr_17:
    cli
    push byte 0
    push byte 17
    jmp isr

isr_18:
    cli
    push byte 0
    push byte 18
    jmp isr

isr_19:
    cli
    push byte 0
    push byte 19
    jmp isr

isr_20:
    cli
    push byte 0
    push byte 20
    jmp isr

isr_21:
    cli
    push byte 0
    push byte 21
    jmp isr

isr_22:
    cli
    push byte 0
    push byte 22
    jmp isr

isr_23:
    cli
    push byte 0
    push byte 23
    jmp isr

isr_24:
    cli
    push byte 0
    push byte 24
    jmp isr

isr_25:
    cli
    push byte 0
    push byte 25
    jmp isr

isr_26:
    cli
    push byte 0
    push byte 26
    jmp isr

isr_27:
    cli
    push byte 0
    push byte 27
    jmp isr

isr_28:
    cli
    push byte 0
    push byte 28
    jmp isr

isr_29:
    cli
    push byte 0
    push byte 29
    jmp isr

isr_30:
    cli
    push byte 0
    push byte 30
    jmp isr

isr_31:
    cli
    push byte 0
    push byte 31
    jmp isr
