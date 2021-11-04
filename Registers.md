-----------------------------------------------
# Registers
Tags:  #Security #Coding 
Creation date: 2021-11-04

-----------------------------------------------

A small amount of memory that is constructed on the chip as a workspace for the processor.

## 64 bit architecture

| 63-32 | 31-16 | 15-08 | 07-00 |        |
| ----- | ----- | ----- | ----- | ------ |
| RAX   |       |       |       | 64 bit |
|       | EAX   |       |       | 32 bit |
|       |       | AX    |       | 16 bit |
|       |       | AH    | AL    | 8 bit  |


Almost always has reverse compatibility.

## IA-32 architecture

There are 8 32 bit data registers `R0-R7`, together with a 32 bit instruction pointer register `EIP` and 32 bit flag register `EFLAGS`

R0-R3 are also called EAX, EBX, ECX, EDX.
R4-R7 are also called ESP (Stack pointer), EBP (Base pointer), ESI, EDI.

`ESI` and `EDI` have special functions when handling strings but can be used as general data registers when not.


## System Calls

System calls allow us to interface with the kernel space which gives us access to OS level functions.

Loading arguments on the stack is done using `int 0x80` in assembly.

`int 0x80`
- The syscall number is loaded into the `EAX` register, this basically tells the system which instruction we want to use.
- Any arguments for a specific syscall are placed into other registers.
- When `int 0x80` is executed the CPU switches to kernel mode and the instruction is executed, then we step back to user mode.

In 32 bit architecture syscalls can have at more 6 arguments, these are placed into `EBX`, `ECX`, `EDX`, `ESI`, `EDI`, and `EPB`. Any additional arguments are passed via pointers.

### Example

`exit()`

Source code:
```c
int main (){
	exit(0);
	return 0;
}
```

Disassembly of main() function
```assembly
mov	ebx,DWORD PTR [esp+0x4]
mov	eax,0xfc
call	DWORD PTR ds:0x80e99f0
mov	eax,0x1
int	0x80
hlt
```

`0x1` is the identifier for the `exit` interrupt, so it's loaded into `EAX` then `int 0x80` in run so the `exit` instruction is executed.


