build: $(PREFIX)/../[BOOT]/[boot].asm
	@if [ ! -d '$(PREFIX)/../build' ]; then mkdir '$(PREFIX)/../build'; fi
	nasm -f bin '$(PREFIX)/../[BOOT]/[boot].asm' -o '$(PREFIX)/../build/[boot].bin'
	@echo "Built [BOOT] to build/"


clear:
	@rm -rf $(PREFIX)/../build
	@echo "Removed build, $(PREFIX)/../build"

