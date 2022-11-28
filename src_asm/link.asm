;
; Author: 	Ice Marek
; Date: 	Summer '22 
; Company: 	IceNET Technology
;
; Order of input arguments
;
; 1st ---> RDI
; 2nd ---> RSI
; 3rh ---> RDX
; 4th ---> RCX
;

section .text

global MEMORY_READ
MEMORY_READ:
	mov rax, rdi
	mov eax, [eax]
	ret

global CALL_POINTER
CALL_POINTER:
	endbr64 
	push rbp
	mov  rbp,rsp
	mov  rax, rdi
	call rax
	pop  rbp
	ret    

section .MemClass

global STACK
STACK:

global HEAP
HEAP:

section .iceNET

global E
E:
	dq 0xEEEEEEEE

global F
F:
	dq 0xFFFFFFFF

