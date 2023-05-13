/*                         */
/* Author: Ice.Marek       */
/* 2023 IceNET Technology  */
/*                         */
ENTRY(_start)

SECTIONS
{
    . = 0x100000; /* set the origin */

    /* text section */
    .text :
    {
        *(.text)
    }

    /* data section */
    .data :
    {
        *(.rodata)
        *(.data)
    }

    /* bss section */
    .bss :
    {
        *(.bss)
    }

    /* heap section */
    .heap :
    {
        HEAP_START = .;
        *(.heap)
        HEAP_END = .;
    }

    /* stack section */
    .stack :
    {
        STACK_START = .;
        . += 0x1000; /* 4KB stack size */
        STACK_END = .;
    }

    /* set the end of the file */
    _end = .;
    PROVIDE(end = .);
}
