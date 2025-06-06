SECTION .bss
tape resb 30000

SECTION .text
GLOBAL _start
_start:
mov edi, 0
inc edi
inc edi
inc edi
inc edi
inc edi
inc edi
inc edi
inc edi
label_start_1:
cmp byte [tape+edi],0
jz label_end_1
inc byte [tape+edi]
inc edi
inc edi
inc edi
inc edi
label_start_2:
cmp byte [tape+edi],0
jz label_end_2
inc byte [tape+edi]
inc edi
inc edi
inc byte [tape+edi]
inc edi
inc edi
inc edi
inc byte [tape+edi]
inc edi
inc edi
inc edi
inc byte [tape+edi]
inc edi
dec byte [tape+edi]
dec byte [tape+edi]
dec byte [tape+edi]
dec byte [tape+edi]
dec edi
jnz label_start_2
label_end_2:
inc byte [tape+edi]
inc edi
inc byte [tape+edi]
inc edi
inc byte [tape+edi]
dec edi
inc byte [tape+edi]
inc byte [tape+edi]
inc edi
label_start_3:
cmp byte [tape+edi],0
jz label_end_3
dec byte [tape+edi]
jnz label_start_3
label_end_3:
dec byte [tape+edi]
dec edi
jnz label_start_1
label_end_1:
inc byte [tape+edi]
inc byte [tape+edi]
mov eax, 4
mov ebx, 1
lea ecx, [tape+edi]
mov edx, 1
int 0x80
inc byte [tape+edi]
dec edi
dec edi
dec edi
mov eax, 4
mov ebx, 1
lea ecx, [tape+edi]
mov edx, 1
int 0x80
inc edi
inc edi
inc edi
inc edi
inc edi
inc edi
inc edi
mov eax, 4
mov ebx, 1
lea ecx, [tape+edi]
mov edx, 1
int 0x80
mov eax, 4
mov ebx, 1
lea ecx, [tape+edi]
mov edx, 1
int 0x80
inc edi
inc edi
inc edi
mov eax, 4
mov ebx, 1
lea ecx, [tape+edi]
mov edx, 1
int 0x80
inc byte [tape+edi]
inc byte [tape+edi]
mov eax, 4
mov ebx, 1
lea ecx, [tape+edi]
mov edx, 1
int 0x80
dec byte [tape+edi]
dec edi
mov eax, 4
mov ebx, 1
lea ecx, [tape+edi]
mov edx, 1
int 0x80
dec byte [tape+edi]
mov eax, 4
mov ebx, 1
lea ecx, [tape+edi]
mov edx, 1
int 0x80
inc edi
inc edi
inc edi
mov eax, 4
mov ebx, 1
lea ecx, [tape+edi]
mov edx, 1
int 0x80
dec edi
dec edi
dec edi
dec edi
dec edi
dec edi
mov eax, 4
mov ebx, 1
lea ecx, [tape+edi]
mov edx, 1
int 0x80
dec edi
dec edi
dec edi
dec edi
dec edi
dec edi
dec edi
dec edi
mov eax, 4
mov ebx, 1
lea ecx, [tape+edi]
mov edx, 1
int 0x80
inc byte [tape+edi]
inc byte [tape+edi]
inc edi
mov eax, 4
mov ebx, 1
lea ecx, [tape+edi]
mov edx, 1
int 0x80
inc byte [tape+edi]
inc edi
inc edi
mov eax, 4
mov ebx, 1
lea ecx, [tape+edi]
mov edx, 1
int 0x80
mov eax, 1
xor ebx, ebx
int 0x80
