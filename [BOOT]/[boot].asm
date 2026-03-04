[org 0x7c00]

KERNEL_OFFSET equ 0x1000

mov [BOOT_DRIVE], dl
mov bp, 0x9000  ; Stack setup
mov sp, bp



call load_kernel
call switch_to_protected



%include "debug/print.asm"
%include "disk/disk.asm"
%include "debug/hex.asm"
%include "protected/gdp.asm"
%include "protected/switch.asm"



;
; Loads kernel into memory
;
[bits 16]
load_kernel:
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
    call KERNEL_OFFSET



BOOT_DRIVE db 0



times 510-($-$$) db 0
dw 0xaa55
