;
; Author: Ice Marek
; 2022 IceNET Technology
;
; Order of input arguments
;
; 1st ---> RCX
; 2nd ---> RDX
; 3rh ---> RSI
; 4th ---> RDI
;

section .text

global MEMORY_READ
MEMORY_READ:
	mov rax, rdi
	mov eax, [eax]
	ret




section .iceNET

global E
E:
	dq 0xEEEEEEEE

global F
F:
	dq 0xFFFFFFFF




section .MemAssembly

global STACK
STACK:
