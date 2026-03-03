BUILD=$(PREFIX)/../build
NAME=galactic-os



build: FORCE
	@if [ ! -d "$(BUILD)" ]; then mkdir $(BUILD); fi

	$(MAKE) bootloader
	$(MAKE) kernel

	@echo "Links bootloader with kernel"
	cat $(BUILD)/[boot].bin $(BUILD)/kernel.bin > $(BUILD)/$(NAME).bin



bootloader: FORCE
	$(MAKE) -C $(PREFIX)/../[BOOT]/

kernel: FORCE
	$(MAKE) -C $(PREFIX)/../[KERNEL]/



clear: FORCE
	@rm -rf $(PREFIX)/../build
	@echo "Removed build, $(PREFIX)/../build"



FORCE:
