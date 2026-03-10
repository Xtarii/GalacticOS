[bits 32]
global enable_paging
enable_paging:
    mov eax, [esp + 4]
    mov cr3, eax

    mov eax, cr0
    or eax, 0x80000000      ; Enables paging
    mov cr0, eax
    ret
