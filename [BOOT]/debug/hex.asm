;
; Prints hex with TTY
;
; : dx - HEX value to print
;
printh:
    pusha
    mov cx, 0

    .hloop:
        cmp cx, 4
        je .hend

        mov ax, dx
        and ax, 0x000f
        add al, 0x30
        cmp al, 0x39
        jle .hstep2
        add al, 7

    .hstep2:
        mov bx, HEX_OUT + 5
        sub bx, cx
        mov [bx], al
        ror dx, 4

        add cx, 1
        jmp .hloop

    .hend:
        mov bx, HEX_OUT
        call print
        popa
        ret



HEX_OUT: db '0x0000', 0
