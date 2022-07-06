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

global _RCX
_RCX:
	mov rax, rdi
	ret

global MEMORY_READ
MEMORY_READ:
	mov rax, rdi
	mov eax, [eax]
	ret

section .iceNET

	global E
	E:
		dq 0xDDDDDDDD

	global F
	F:
		dq 0xEEEEEEEE

section .MemAssembly

	global STACK
	STACK:

	global HEAP
	HEAP:
