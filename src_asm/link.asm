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

global CALL_PROCEDURE
CALL_PROCEDURE:
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

section .iceNET

global X
X:
	dq 0x11112222
	dq 0x33334444
	dq 0x55556666

