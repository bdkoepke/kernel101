;; kernel.asm
bits 32 ; nasm directive for the NASM assembler that specifies that it should
        ; generate code that runs on a processor in 32-bit mode

[section .text]
  ; multiboot spec
  align 4
  dd 0x1BADB002 ; magic
  dd 0x00 ; flags
  dd  - (0x1BADB002 + 0x00) ; checksum. m+f+c should be zero

[section .bss align=16]
  resb 8192 ; need to reserve some bytes in the bss section of the executable
            ; for the stack
  stack_end:

global start
extern kmain

start:
  cli ; block interrupts
  mov esp, stack_end
  call kmain
  hlt ; halt the CPU
