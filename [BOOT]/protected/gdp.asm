startg:
    dd 0x0
    dd 0x0

codeg:
    dw 0xffff
    dw 0x0
    db 0x0
    db 10011010b
    db 11001111b
    db 0x0

datag:
    dw 0xffff
    dw 0x0
    db 0x0
    db 10010010b
    db 11001111b
    db 0x0

endg:

descriptorg:
    dw endg - startg - 1
    dd startg



CODE_SEG equ codeg - startg
DATA_SEG equ datag - startg
