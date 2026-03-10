[extern isr_handler]
[extern irq_handler]

isr:
    pusha
    mov ax, ds
    push eax
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    push esp

    cld
    call isr_handler

    pop eax
    pop eax
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    popa
    add esp, 8
    iret

irq:
    pusha
    mov ax, ds
    push eax
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    push esp

    cld
    call irq_handler

    pop ebx
    pop ebx
    mov ds, bx
    mov es, bx
    mov fs, bx
    mov gs, bx
    popa
    add esp, 8
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

;
; Interrupt requests
;
global irq_0
global irq_1
global irq_2
global irq_3
global irq_4
global irq_5
global irq_6
global irq_7
global irq_8
global irq_9
global irq_10
global irq_11
global irq_12
global irq_13
global irq_14
global irq_15



isr_0:
    push byte 0
    push byte 0
    jmp isr

isr_1:
    push byte 0
    push byte 1
    jmp isr

isr_2:
    push byte 0
    push byte 2
    jmp isr

isr_3:
    push byte 0
    push byte 3
    jmp isr

isr_4:
    push byte 0
    push byte 4
    jmp isr

isr_5:
    push byte 0
    push byte 5
    jmp isr

isr_6:
    push byte 0
    push byte 6
    jmp isr

isr_7:
    push byte 0
    push byte 7
    jmp isr

isr_8:
    push byte 8
    jmp isr

isr_9:
    push byte 0
    push byte 9
    jmp isr

isr_10:
    push byte 10
    jmp isr

isr_11:
    push byte 11
    jmp isr

isr_12:
    push byte 12
    jmp isr

isr_13:
    push byte 13
    jmp isr

isr_14:
    push byte 14
    jmp isr

isr_15:
    push byte 0
    push byte 15
    jmp isr

isr_16:
    push byte 0
    push byte 16
    jmp isr

isr_17:
    push byte 0
    push byte 17
    jmp isr

isr_18:
    push byte 0
    push byte 18
    jmp isr

isr_19:
    push byte 0
    push byte 19
    jmp isr

isr_20:
    push byte 0
    push byte 20
    jmp isr

isr_21:
    push byte 0
    push byte 21
    jmp isr

isr_22:
    push byte 0
    push byte 22
    jmp isr

isr_23:
    push byte 0
    push byte 23
    jmp isr

isr_24:
    push byte 0
    push byte 24
    jmp isr

isr_25:
    push byte 0
    push byte 25
    jmp isr

isr_26:
    push byte 0
    push byte 26
    jmp isr

isr_27:
    push byte 0
    push byte 27
    jmp isr

isr_28:
    push byte 0
    push byte 28
    jmp isr

isr_29:
    push byte 0
    push byte 29
    jmp isr

isr_30:
    push byte 0
    push byte 30
    jmp isr

isr_31:
    push byte 0
    push byte 31
    jmp isr

;
; Interrupt request handlers
;
irq_0:
    push byte 0
    push byte 32
    jmp irq

irq_1:
    push byte 1
    push byte 33
    jmp irq

irq_2:
    push byte 2
    push byte 34
    jmp irq

irq_3:
    push byte 3
    push byte 35
    jmp irq

irq_4:
    push byte 4
    push byte 36
    jmp irq

irq_5:
    push byte 5
    push byte 37
    jmp irq

irq_6:
    push byte 6
    push byte 38
    jmp irq

irq_7:
    push byte 7
    push byte 39
    jmp irq

irq_8:
    push byte 8
    push byte 40
    jmp irq

irq_9:
    push byte 9
    push byte 41
    jmp irq

irq_10:
    push byte 10
    push byte 42
    jmp irq

irq_11:
    push byte 11
    push byte 43
    jmp irq

irq_12:
    push byte 12
    push byte 44
    jmp irq

irq_13:
    push byte 13
    push byte 45
    jmp irq

irq_14:
    push byte 14
    push byte 46
    jmp irq

irq_15:
    push byte 15
    push byte 47
    jmp irq
