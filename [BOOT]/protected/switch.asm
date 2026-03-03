;
; Switches to 32 bit protected mode
;
[bits 16]
switch:
    cli
    lgdt [descriptorg]
    mov eax, cr0
    or eax, 0x1
    mov cr0, eax
    jmp CODE_SEG:init



;
; 32 bit initialization
;
[bits 32]
init:
    mov ax, DATA_SEG
    mov ds, ax
    mov ss, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    mov ebp, 0x90000
    mov esp, ebp

    call ENTER
