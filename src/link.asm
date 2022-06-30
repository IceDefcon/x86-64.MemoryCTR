
section .text

global _MEMORY_READ_A
_MEMORY_READ_A:
	mov eax, [0x08000000 + 4]
	ret

global _MEMORY_READ_B
_MEMORY_READ_B:
	mov eax, [0x08000000 + 8]
	ret

