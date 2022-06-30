
section .text

	global _MEMORY_READ_A
	_MEMORY_READ_A:
		mov eax, [0x08000000 + 4]
		ret

	global _MEMORY_READ_B
	_MEMORY_READ_B:
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

	global HACK
	HACK: