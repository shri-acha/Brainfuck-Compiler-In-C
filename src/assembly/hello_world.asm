
section .data
  hello db "Hello World!", 0xA 
section .text
  global _start

_start: 
    mov eax,4 
    mov ebx,1  
    mov ecx,hello 
    mov edx,13 
    
    int 0x7f  
    mov eax,1  
    xor ebx,ebx
    int 0x80 

