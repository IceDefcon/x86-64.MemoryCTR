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

global Return_4x_16bit_arguments
Return_4x_16bit_arguments:
	mov rax, rcx 		; 4th input argument RDI ---> RAX
	shl rax, $10 		; Shift RAX 16bits Left
	add rax, rdx 		; 3rh input argument RSI ---> RAX
	shl rax, $10 		; Shift RAX 16bit Left
	add rax, rsi 		; 2nd input argument RDX ---> RAX
	shl rax, $10 		; Shift RAX 16bit Left
	add rax, rdi 		; 1st input argument RCX ---> RAX
	ret 				; Return all input arguments into 64bit variable ----> 4x16bit = 64bit variable

global _RCX
_RCX:
	mov rax, rdi
	ret

global MEMORY_READ
MEMORY_READ:
	mov rax, rdi
	mov eax, [eax]
	ret

global MEMORY_READ_A
MEMORY_READ_A:
	mov eax, [0x8000300]
	ret

global MEMORY_READ_B
MEMORY_READ_B:
	mov eax, [0x8000300 + 0x4]
	ret

global MEMORY_READ_C
MEMORY_READ_C:
	mov eax, [0x8000300 + 0x8]
	ret

global MEMORY_READ_D
MEMORY_READ_D:
	mov eax, [0x8000300 + 0xC]
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
