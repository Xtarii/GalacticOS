[bits 32]

VIDEO_MEMORY equ 0xb8000
WHITE_ON_BACK equ 0x0f

;
; Prints string on screen in protected (32 bit) mode
;
; : ebx - String to print
;
pprint:
    pusha
    mov edx, VIDEO_MEMORY

    .ploop:
        mov al, [ebx]
        mov ah, WHITE_ON_BACK

        cmp al, 0
        je .pend

        mov [edx], ax
        add ebx, 1  ; Next char
        add edx, 2  ; Next position

        jmp .ploop

    .pend:
        popa
        ret
