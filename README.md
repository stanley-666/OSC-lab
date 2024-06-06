# Self-study NYCU OSC
# From 0 to 100 learning how to develop a kernel
## LAB0
[My lab0 notes](https://hackmd.io/O0KcM_6qQFqDFVKk5-PHlA)
file:
a.S : startup code for an ARM Cortex-A processor
linker.ld : allocation program memory layout, .start,.text, .data ..etc
flow:
1. .c compiled to .S then assembler turn .S into machine code .o
2. linker links .o into elf file 
3. elf header gives loader( program ) information to relocate and load into memory
