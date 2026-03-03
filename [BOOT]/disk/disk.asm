;
; Loads data from disk
;
; : dh - Number of sectors to read
;
loadd:
    pusha
    push dx

    mov ah, 0x02
    mov al, dh
    mov cl, 0x02

    mov ch, 0x00
    mov dh, 0x00

    int 0x13
    jc .derror

    pop dx
    cmp al, dh
    jne .dserror
    popa
    ret


    .derror:
        mov bx, DISK_ERROR
        call print
        call println
        mov dh, ah
        call printh
        jmp .dloop

    .dserror:
        mov bx, DISK_SECTOR_ERROR
        call print

    .dloop:
        jmp $



DISK_ERROR: db "Disk reading error", 0
DISK_SECTOR_ERROR: db "Incorrect number of sectors read", 0
