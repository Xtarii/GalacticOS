BUILD=$(PREFIX)/../build
CFLAGS=-g -ffreestanding

KERNEL_DEPENDENCIES=output kernel.c entry.asm ports.o screen.o utils.o cpu



kernel: ${KERNEL_DEPENDENCIES}
	@echo "Compiles kernel..."
	$(TARGET)-gcc $(CFLAGS) -c kernel.c -o $(BUILD)/kernel.o
	nasm entry.asm -f elf -o $(BUILD)/entry.o

	@$(TARGET)-ld -o $(BUILD)/kernel.bin -Ttext 0x1000 \
		$(BUILD)/entry.o \
		$(BUILD)/kernel.o \
		$(BUILD)/ports.o \
		$(BUILD)/screen.o \
		$(BUILD)/utils.o \
		$(BUILD)/IDT.o \
		$(BUILD)/ISR.o \
		$(BUILD)/interrupt.o \
		--oformat binary

	@$(TARGET)-ld -o $(BUILD)/kernel-debug.elf -Ttext 0x1000 \
		$(BUILD)/entry.o \
		$(BUILD)/kernel.o \
		$(BUILD)/ports.o  \
		$(BUILD)/utils.o \
		$(BUILD)/screen.o \
		$(BUILD)/IDT.o \
		$(BUILD)/ISR.o \
		$(BUILD)/interrupt.o

	$(MAKE) clear-build



ports.o: drivers/ports.c drivers/ports.h
	$(TARGET)-gcc $(CFLAGS) -c $< -o $(BUILD)/$@

screen.o: drivers/screen.c drivers/screen.h
	$(TARGET)-gcc $(CFLAGS) -c $< -o $(BUILD)/$@

utils.o: utilities/utils.c utilities/utils.h
	$(TARGET)-gcc $(CFLAGS) -c $< -o $(BUILD)/$@

cpu: cpu/IDT.c cpu/IDT.h cpu/ISR.c cpu/ISR.h cpu/interrupt.asm
	$(TARGET)-gcc $(CFLAGS) -c cpu/IDT.c -o $(BUILD)/IDT.o
	$(TARGET)-gcc $(CFLAGS) -c cpu/ISR.c -o $(BUILD)/ISR.o
	nasm cpu/interrupt.asm -f elf -o $(BUILD)/interrupt.o





output: $(BUILD)
	mkdir -p $(BUILD)



clear-build:
	@echo "Preforms a cleanup of unused files in build"
	rm -rf \
		$(BUILD)/entry.o \
		$(BUILD)/kernel.o \
		$(BUILD)/ports.o \
		$(BUILD)/screen.o \
		$(BUILD)/utils.o \
		$(BUILD)/IDT.o \
		$(BUILD)/ISR.o \
		$(BOOT)/interrupt.o
