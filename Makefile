BUILD=$(PREFIX)/../build
OUT=$(BUILD)/out

NAME=galactic-os



build: FORCE $(BUILD) $(OUT)
	$(MAKE) bootloader
	$(MAKE) kernel

	@echo "Links bootloader with kernel"
	cat $(BUILD)/[boot].bin $(BUILD)/kernel.bin > $(OUT)/$(NAME).bin



debug: build
	qemu-system-i386 -s -S -fda $(OUT)/$(NAME).bin &
	gdb $(BUILD)/kernel-debug.elf \
		-ex "set architecture i386" \
		-ex "target remote localhost:1234"



bootloader: FORCE $(BUILD)
	$(MAKE) -C $(PREFIX)/../[BOOT]/

kernel: FORCE $(BUILD)
	$(MAKE) -C $(PREFIX)/../[KERNEL]/



clear: FORCE $(BUILD)
	@rm -rf $(PREFIX)/../build
	@echo "Removed build, $(PREFIX)/../build"



FORCE:



$(BUILD):
	mkdir -p $(BUILD)

$(OUT):
	mkdir -p $(OUT)
