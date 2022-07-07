SECTIONS
{
  . = 0x2000000;
  .text : { *(.text) }
  . = 0x4000000;
  .data : { *(.data) }
  . = 0x6000000;
  .bss : { *(.bss) }
  . = 0x8000000;
  .iceNET : { *(.iceNET)}
  . = 0xA000000;
  .MemAssembly : { *(.MemAssembly)}
}