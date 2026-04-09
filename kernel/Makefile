BUILD=$(PREFIX)/../build

CFLAGS=-std=gnu99 -O2 -Wall -Wextra -ffreestanding
GCC = $(TARGET)-gcc $(CFLAGS)

DEPENDS=CPU



kernel.o: $(BUILD) kernel.c $(DEPENDS)
	$(GCC) -c kernel.c -o $(BUILD)/kernel.o



CPU: cpu/*
	$(GCC) -c cpu/gdt/GDT.c -o $(BUILD)/GDT.o
	$(GCC) -c cpu/interrupts/IDT.c -o $(BUILD)/IDT.o
	$(GCC) -c cpu/interrupts/ISR.c -o $(BUILD)/ISR.o

	nasm cpu/gdt/GDT.asm -f elf -o $(BUILD)/GDT_asm.o
	nasm cpu/interrupts/interrupt.asm -f elf -o $(BUILD)/interrupt.o



$(BUILD):
	mkdir -p $(BUILD)
