section .data
section .bss
section .text
      global _start
_start
mov eax,1 ; Exit system call
mov ebx,0 ;  Return value
int 80h ; Interupt to Operating System