BUILD=$(PREFIX)/../build
CFLAGS=-g -ffreestanding



kernel: kernel.c entry.asm build-dependencies build-screen $(BUILD)/utils.o
	@echo "Compiles kernel..."
	$(TARGET)-gcc $(CFLAGS) -c kernel.c -o $(BUILD)/kernel.o
	nasm entry.asm -f elf -o $(BUILD)/entry.o

	$(TARGET)-ld -o $(BUILD)/kernel.bin -Ttext 0x1000 \
		$(BUILD)/entry.o \
		$(BUILD)/kernel.o \
		$(BUILD)/ports.o \
		$(BUILD)/screen.o \
		$(BUILD)/utils.o \
		--oformat binary

	$(TARGET)-ld -o $(BUILD)/kernel-debug.elf -Ttext 0x1000 \
		$(BUILD)/entry.o \
		$(BUILD)/kernel.o \
		$(BUILD)/ports.o  \
		$(BUILD)/utils.o \
		$(BUILD)/screen.o

	$(MAKE) clear-build



build-dependencies: drivers/ports.c drivers/ports.h
	$(TARGET)-gcc $(CFLAGS) -c drivers/ports.c -o $(BUILD)/ports.o

build-screen: drivers/screen.c drivers/screen.h
	$(TARGET)-gcc $(CFLAGS) -c drivers/screen.c -o $(BUILD)/screen.o

$(BUILD)/utils.o : utilities/utils.c utilities/utils.h
	$(TARGET)-gcc $(CFLAGS) -c $< -o $@



clear-build:
	@echo "Preforms a cleanup of unused files in build"
	rm -rf \
		$(BUILD)/entry.o \
		$(BUILD)/kernel.o \
		$(BUILD)/ports.o \
		$(BUILD)/screen.o
