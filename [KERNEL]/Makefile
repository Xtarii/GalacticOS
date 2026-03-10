ROOT=$(PREFIX)/..
BUILD=$(PREFIX)/../build

CFLAGS=-g -m32 -fno-builtin -fno-stack-protector \
	-nostartfiles -nodefaultlibs -ffreestanding -Wall -Wextra -Werror

GCC=$(TARGET)-gcc $(CFLAGS)

KERNEL_DEPENDENCIES=output kernel.c entry.asm cpu drivers libc



kernel: ${KERNEL_DEPENDENCIES}
	@echo "Compiles kernel..."
	$(GCC) -c kernel.c -o $(BUILD)/kernel.o
	nasm entry.asm -f elf -o $(BUILD)/entry.o

	@$(TARGET)-ld -o $(BUILD)/kernel.bin -T linker.ld \
		$(BUILD)/entry.o \
		$(BUILD)/kernel.o \
		$(BUILD)/ports.o \
		$(BUILD)/screen.o \
		$(BUILD)/IDT.o \
		$(BUILD)/ISR.o \
		$(BUILD)/IRQ.o \
		$(BUILD)/timer.o \
		$(BUILD)/interrupt.o \
		$(BUILD)/keyboard.o \
		$(BUILD)/memory.o \
		$(BUILD)/string.o \
		--oformat binary

	@$(TARGET)-ld -o $(BUILD)/kernel-debug.elf -T linker.ld \
		$(BUILD)/entry.o \
		$(BUILD)/kernel.o \
		$(BUILD)/ports.o  \
		$(BUILD)/screen.o \
		$(BUILD)/IDT.o \
		$(BUILD)/ISR.o \
		$(BUILD)/IRQ.o \
		$(BUILD)/timer.o \
		$(BUILD)/interrupt.o\
		$(BUILD)/keyboard.o \
		$(BUILD)/memory.o \
		$(BUILD)/string.o

	$(MAKE) clear-build



libc: $(ROOT)/libc/*.c $(ROOT)/libc/*.h
	$(GCC) -c $(ROOT)/libc/memory.c -o $(BUILD)/memory.o
	$(GCC) -c $(ROOT)/libc/string.c -o $(BUILD)/string.o

cpu: cpu/IDT.c cpu/IDT.h cpu/ISR.c cpu/ISR.h cpu/interrupt.asm cpu/IRQ.c cpu/IRQ.h cpu/timer.c cpu/timer.h
	$(GCC) -c cpu/IDT.c -o $(BUILD)/IDT.o
	$(GCC) -c cpu/ISR.c -o $(BUILD)/ISR.o
	$(GCC) -c cpu/IRQ.c -o $(BUILD)/IRQ.o
	$(GCC) -c cpu/timer.c -o $(BUILD)/timer.o
	nasm cpu/interrupt.asm -f elf -o $(BUILD)/interrupt.o

drivers: drivers/keyboard.c drivers/keyboard.h drivers/ports.c drivers/ports.h drivers/screen.c drivers/screen.h
	$(GCC) -c drivers/ports.c -o $(BUILD)/ports.o
	$(GCC) -c drivers/screen.c -o $(BUILD)/screen.o
	$(GCC) -c drivers/keyboard.c -o $(BUILD)/keyboard.o





output: $(BUILD)
	mkdir -p $(BUILD)



clear-build:
	@echo "Preforms a cleanup of unused files in build"
	rm -rf \
		$(BUILD)/entry.o \
		$(BUILD)/kernel.o \
		$(BUILD)/ports.o \
		$(BUILD)/screen.o \
		$(BUILD)/IDT.o \
		$(BUILD)/ISR.o \
		$(BUILD)/IRQ.o \
		$(BUILD)/timer.o \
		$(BOOT)/interrupt.o \
		$(BUILD)/keyboard.o \
		$(BUILD)/memory.o \
		$(BUILD)/string.o
