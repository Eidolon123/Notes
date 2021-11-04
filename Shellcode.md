-----------------------------------------------
# Shellcode
Tags:  #Security #Coding 
Creation date: 2021-11-04

-----------------------------------------------

Original definition: A small piece of code used as the payload of a virus or other malware, used to spawn a shell.

Newer definition: Malware programming code that is injected covertly into the computer. Any machine language embedded in data that is used to compromise either the local machine or a remote machine.

## Constructing shellcode

This is an example of constructing shellcode to call the `exit()` instruction.

Source code:
```assembly
Section.text
	global _start
	
_start:
	
	mov ebx, 0
	mov eax, 1
	int 0x80
```
Here we store 0 in the `ebx` [[Registers|register]], 1 int the `eax` [[Registers|register]], then tell the system to execute the system call stored in `eax`. 1 is the identifier for `exit()`.

objdump of the assembled code above:
```
objdump -M intel -d exit_shell.o

exit_shell.o:     file format elf32-i386


Disassembly of section .text:

00000000 <_start>:
   0:	bb 00 00 00 00       	mov    ebx,0x0
   5:	b8 01 00 00 00       	mov    eax,0x1
   a:	cd 80                	int    0x80
```

As we can see there are a lot of zeros which could be interpreted as string terminators if we were to convert this payload into a string of characters. This would mean we would read in the opcodes `0xbb`, then `0x00` would be interpreted as end of string and the program would stop.

### Circumventing the string terminator

What we can do to avoid this problem with `0x00` is to use functionally equivalent instructions using `XOR` or 8 bit [[Registers]] `AL` and `AH`. `XOR` is useful as if a [[Registers|register]] is XORed with itself, it will always be 0.

We can now rewrite the shellcode to avoid this issue:

Source code:
```
Section.text
	global _start
	
_start:

	xor ebx, ebx
	mov al, 1
	int 0x80
```

objdump of above code:

```
objdump -M intel -d exit_shell.o

exit_shell.o:     file format elf32-i386


Disassembly of section .text:

00000000 <_start>:
   0:	31 db                	xor    ebx,ebx
   2:	b0 01                	mov    al,0x1
   4:	cd 80                	int    0x80
```

Here we can see that using the functionally equivalent code has reduced our shellcode down substantially and removed all zeros.

### General steps for constructing shellcode

- Write the shellcode in a suitable high-level language
- Compile and disassemble the program
- Analyse program functionality at the assembly level, check the interrupt calls.
- Clean up the assembly, compact it as far as possible and remove nulls using semantic equivalence.
- Extract the opcodes and build the shellcode.