;
; Prints string with TTY
;
; : bx - String to print
;
print:
    pusha

    .pstart:
        mov al, [bx]
        cmp al, 0
        je .pend

        mov ah, 0x0e
        int 0x10

        add bx, 1
        jmp .pstart

    .pend:
        popa
        ret



;
; Prints new line
;
println:
    pusha

    mov ah, 0x0e

    mov al, 0x0a    ; New line
    int 0x10

    mov al, 0x0d    ; Carriage
    int 0x10

    popa
    ret
