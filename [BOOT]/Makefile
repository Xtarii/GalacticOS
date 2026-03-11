BUILD=$(PREFIX)/../build



boot.o: $(BUILD) boot.s
	$(TARGET)-as boot.s -o $(BUILD)/boot.o



$(BUILD):
	mkdir -p $(BUILD)
