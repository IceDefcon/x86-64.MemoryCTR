
section .text

	global MEMORY_READ_A
	MEMORY_READ_A:
		mov eax, [0x08000000 + 4]
		ret

	global MEMORY_READ_B
	MEMORY_READ_B:
		mov eax, [0x08000000 + 8]
		ret

section .iceNET

	global C
	C:
		dq 0xCCCCCCCC

	global D
	D:
		dq 0xDDDDDDDD

section .iceHACK

	global STACK
	STACK:
		db 0xAB

	global HEAP
	HEAP:
		db 0xCD