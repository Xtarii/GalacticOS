# Galactic OS
Simply a useless operating system.
Sources,
> - [OS Tutorial](https://github.com/cfenollosa/os-tutorial)
> - [OSDev Wiki](https://wiki.osdev.org/Expanded_Main_Page)


### Environment
Set up the development environment before calling any other commands.
```bash
export PREFIX="<path>/cross"
export TARGET=i686-elf
export PATH="$PREFIX/bin:$PATH"
```

Note `path` is where the project is located. `cross` is a subdirectory for the cross-compiler while `path` will be where the hole projected is stored.
Build files will build to `path/build`


### Running
Current command for running the project
```bash
qemu-system-x86_64 -fda build/out/galactic-os.bin   # In project root path
```

For debugging run
```bash
make debug
```
