[org 0x7c00]

KERNEL_OFFSET equ 0x1000

mov [BOOT_DRIVE], dl
mov bp, 0x9000  ; Stack setup
mov sp, bp


mov bx, MESSAGE_RM
call print
call println

call load_kernel
call switch_to_protected
jmp $   ; Should never be called



%include "debug/print.asm"
%include "debug/pprint.asm"
%include "disk/disk.asm"
%include "debug/hex.asm"
%include "protected/gdp.asm"
%include "protected/switch.asm"



;
; Loads kernel into memory
;
[bits 16]
load_kernel:
    mov bx, MESSAGE_LOAD_KERNEL_RM
    call print
    call println

    mov bx, KERNEL_OFFSET
    mov dh, 2
    mov dl, [BOOT_DRIVE]
    call load_disk
    ret

;
; 32-bit entry point
;
[bits 32]
PM_ENTRYPOINT:
    mov ebx, MESSAGE_PM
    call pprint
    call KERNEL_OFFSET
    jmp $   ; Loop when kernel returns controls



BOOT_DRIVE db 0

MESSAGE_RM db "Real mode (16 bit) loaded", 0
MESSAGE_LOAD_KERNEL_RM db "Loading kernel into memory...", 0
MESSAGE_PM db "Protected mode (32 bit) loaded", 0



times 510-($-$$) db 0
dw 0xaa55
