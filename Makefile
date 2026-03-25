BUILD=$(PREFIX)/../build
OUT=$(BUILD)/out
BOOT=$(BUILD)/iso/boot

NAME=galactic-os

CFLAGS=-ffreestanding -O2 -nostdlib -lgcc
GCC=$(TARGET)-gcc $(CFLAGS)



bootable: $(BOOT) build grub.cfg
	cp $(BUILD)/$(NAME) $(BOOT)/$(NAME)
	cp grub.cfg $(BOOT)/grub/grub.cfg
	grub2-mkrescue -o $(OUT)/$(NAME).iso $(BOOT)/../



build: $(BUILD) $(OUT) FORCE
	$(MAKE) -C "./[BOOT]/"
	$(MAKE) -C "./kernel/"
	$(GCC) -T linker.ld -o $(BUILD)/$(NAME) \
		$(BUILD)/boot.o \
		$(BUILD)/kernel.o \
		$(BUILD)/GDT.o \
		$(BUILD)/GDT_asm.o



debug: bootable
	qemu-system-i386 -cdrom $(OUT)/$(NAME).iso



$(BUILD):
	mkdir -p $(BUILD)

$(OUT):
	mkdir -p $(OUT)

$(BOOT):
	mkdir -p $(BOOT)/grub

FORCE:
