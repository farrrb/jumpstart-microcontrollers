/* Linker Script for NRF51822-QFAA-R rev3 */

/* Defines the programs entry point */
ENTRY(Reset_Handler)

/* Define Memory Segments */
MEMORY
{
  FLASH (rx)  : ORIGIN = 0x00000000, LENGTH = 0x40000 /* 256 KByte = 256 * 1024 =  262144 = 0x40000 */
  RAM   (rwx) : ORIGIN = 0x20000000, LENGTH = 0x4000  /*  16 KByte =  16 * 1024 =   16384 = 0x4000  */
}

/* Section Definition and Memory Mapping */
SECTIONS
{
  /* .stack_pointer */
  .stack_pointer :
  {
    KEEP(*(.stack_pointer))
  } > FLASH

  /* .isr_vectors section - */
  .isr_vectors :
  {
    KEEP(*(.isr_vectors))
  } > FLASH

  /* .text section - */
  .text :
  {
    . = ALIGN(4);
    *(.text*)
  } > FLASH

  /* .preinit_array section - */
  .preinit_array :
  {
    . =  ALIGN(4);
    __preinit_array_start__ = .;
    KEEP(*(.preinit_array*))
    __preinit_array_end__ = .;
  } > FLASH

  /* .init_array section - */
  .init_array :
  {
    . =  ALIGN(4);
    __init_array_start__ = .;
    KEEP(*(.init_array*))
    __init_array_end__ = .;
  } > FLASH

  /* .fini_array section - */
  .fini_array :
  {
    . =  ALIGN(4);
    __fini_array_start__ = .;
    KEEP(*(.fini_array*))
    __fini_array_end__ = .;
  } > FLASH

  /* .rodata section - */
  .rodata :
  {
    . = ALIGN(4);
    *(.rodata*)
  } > FLASH

  /* .data section - */
  .data :
  {
    . = ALIGN(4);
    __data_start__ = .;
    *(.data*)
    . = ALIGN(4);
    __data_end__ = .;
  } > RAM AT > FLASH /* Tell the linker that there will be a loading from FLASH */
  /*
   * Define  __data_load which specifies the start address in the FLASH memory
   * from where to load the initialized data to RAM.
   */
  __data_load__ = LOADADDR(.data);

  /* .bss section - */
  .bss :
  {
    . = ALIGN(4);
    __bss_start__ = .;
    *(.bss*)
    *(COMMON)
    . = ALIGN(4);
    __bss_end__ = .;
  } > RAM

  /* .heap section - */
  .heap (NOLOAD):
  {
    . = ALIGN(8);
    __heap_start__ = .;
    KEEP(*(.heap*))
    __heap_end__ = .;
  } > RAM

  /* .stack section - */
  .stack (NOLOAD):
  {
    . = ALIGN(8);
    __stack_end__ = .; /* Stack is growing down (decreasing) */
    KEEP(*(.stack*))
  } > RAM

  /* Define __stack_top at the end of the RAM */
  __stack_top = ORIGIN(RAM) + LENGTH(RAM);
}
