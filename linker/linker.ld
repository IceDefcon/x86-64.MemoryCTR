SECTIONS
{
  . = 0x1000000;
  .text : { *(.text) }
  . = 0x8000000;
  .data : { *(.data) }
  .bss : { *(.bss) }
  . = 0xA000000;
  .iceNET : { *(.iceNET)}
  . = 0xB000000;
  .iceHACK : { *(.iceHACK)}
}