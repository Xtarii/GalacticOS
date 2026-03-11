BUILD=$(PREFIX)/../build

CFLAGS=-std=gnu99 -O2 -Wall -Wextra -ffreestanding
GCC = $(TARGET)-gcc $(CFLAGS)



kernel.o: $(BUILD) kernel.c
	$(GCC) -c kernel.c -o $(BUILD)/kernel.o



$(BUILD):
	mkdir -p $(BUILD)
