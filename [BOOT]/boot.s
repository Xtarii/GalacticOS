.set ALIGN,      1 << 0
.set MEMINFO,    1 << 1
.set FLAGS,      ALIGN | MEMINFO
.set MAGIC,      0x1BADB002
.set CHECKSUM,   -(MAGIC + FLAGS)


.section    .multiboot.data, "aw"
.align      4
.long       MAGIC
.long       FLAGS
.long       CHECKSUM


# Initial stack setup
.global stack_top
.section    .bootstrap_stack, "aw", @nobits
stack_bottom:
.skip       16384
stack_top:


# Preallocation for pages
.section    .bss, "aw", @nobits
    .align  4096
boot_page_directory:
    .skip   4096
boot_page_table:
    .skip   4096


# Kernel entry point
.section    .multiboot.text, "a"
.global     _start
.type       _start, @function
_start:
    movl $(boot_page_table - 0xC0000000),  %edi
    movl $0, %esi
    movl $1023, %ecx


    1:
        cmpl $_kernel_start, %esi
        jl 2f
        cmpl $(_kernel_end - 0xC0000000), %esi
        jge 3f

        movl %esi, %edx
        orl $0x003, %edx
        movl %edx, (%edi)

    2:
        addl $4096, %esi
        addl $4, %edi
        loop 1b

    3:
        # Map VGA video memory to 0xC03FF000 as "present, writable".
    	movl $(0x000B8000 | 0x003), boot_page_table - 0xC0000000 + 1023 * 4


        # Sets paging entries for higher-half kernel
        movl $(boot_page_table - 0xC0000000 + 0x003), boot_page_directory - 0xC0000000 + 0
    	movl $(boot_page_table - 0xC0000000 + 0x003), boot_page_directory - 0xC0000000 + 768 * 4

        movl $(boot_page_directory - 0xC0000000), %ecx
        movl %ecx, %cr3
        movl %cr0, %ecx
        orl $0x80010000, %ecx   # Enable paging and the write-protect bit.
        movl %ecx, %cr0

        lea 4f, %ecx
        jmp *%ecx


.section    .text
    4:
        movl $0, boot_page_directory + 0    # Removes the first entry in paging table

        movl %cr3, %ecx
        movl %ecx, %cr3

        mov $stack_top, %esp
        call kernel_main                    # Jumps to kernel main

        cli
        1:
            hlt
        jmp 1b
