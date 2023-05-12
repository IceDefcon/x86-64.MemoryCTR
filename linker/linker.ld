/*                         */
/* Author: Ice.Marek       */
/* 2023 IceNET Technology  */
/*                         */
SECTIONS
{
  . = 0x2000000;  .text     : { *(.text) }
  . = 0x4000000;  .data     : { *(.data) }
  . = 0x6000000;  .bss      : { *(.bss) }
}