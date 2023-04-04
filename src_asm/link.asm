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
	dd 0x7777
	dd 0x8888
	dd 0


locked:
	dd 0

global SPIN_LOCK
SPIN_LOCK:
	mov eax, 1  		; Set EAX = 1
	xchg eax,[locked] 	; Swap EAX with lock variable 
	test eax, eax 		; If EAX = 0 ---> ZF = 0
	jnz SPIN_LOCK 		; If ZF != 0 then jump to spin_lock
	ret 				; If the spin is locked then procedure will run in a loop until released

global SPIN_UNLOCK
SPIN_UNLOCK:
	xor eax, eax 		; Zero EAX register
	xchg eax, [locked] 	; Swap EAX with lock variable
	ret 				; Lock has been released 
