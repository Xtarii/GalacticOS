[org 0x7c00]

mov bp, 0x9000  ; Stack setup
mov sp, bp



mov bx, RM_MESSAGE
call print

call switch
jmp $   ; Should never be called



%include "[BOOT]/debug/print.asm"
%include "[BOOT]/debug/pprint.asm"
; %include "[BOOT]/debug/hex.asm"
; %include "[BOOT]/disk/disk.asm"
%include "[BOOT]/protected/gdp.asm"
%include "[BOOT]/protected/switch.asm"



[bits 32]
ENTER:
    mov ebx, PM_MESSAGE
    call pprint
    jmp $



RM_MESSAGE: db "Real mode (16 bit) loaded", 0
PM_MESSAGE: db "Protected mode (32 bit) loaded", 0



times 510-($-$$) db 0
dw 0xaa55
