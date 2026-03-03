BUILD=$(PREFIX)/../build



kernel: kernel.c entry.asm
	@echo "Compiles kernel..."
	$(TARGET)-gcc -ffreestanding -c kernel.c -o $(BUILD)/kernel.o
	nasm entry.asm -f elf -o $(BUILD)/entry.o

	$(TARGET)-ld -o $(BUILD)/kernel.bin -Ttext 0x1000 \
		$(BUILD)/entry.o \
		$(BUILD)/kernel.o \
		--oformat binary

	$(MAKE) clear-build



clear-build:
	@echo "Preforms a cleanup of unused files in build"
	rm -rf \
		$(BUILD)/entry.o \
		$(BUILD)/kernel.o
