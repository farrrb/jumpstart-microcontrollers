/// Startup Code

#include <stdint.h>

#include "startup_config.h"

#include "linker_symbols.h"
#include "isr_vectors.h"

extern int main(void);

__attribute__((always_inline)) static inline uint32_t get_msp(void)
{
  register uint32_t result;

  asm volatile ("MRS %0, msp\n" : "=r" (result) );

  return(result);
}

__attribute__((always_inline)) static inline void set_msp(uint32_t stacktop)
{
  asm volatile ("MSR msp, %0\n" : : "r" (stacktop) : "sp");
}

 __attribute__((always_inline)) static inline void set_psp(uint32_t stacktop)
{
  asm volatile ("MSR psp, %0\n" : : "r" (stacktop) : "sp");
}

static inline void fill_stack(void)
{
  // Stack grows down, so we start from the __stack_end__ all the way to the
  // current stack pointer.
  register uint32_t *dst = &__stack_end__;
  register uint32_t *end = (uint32_t *)get_msp();

  while (dst < end)
  {
    *dst++ = (uint32_t)STACK_MAGIC;
  }
}

static inline void fill_heap(void)
{
  register uint32_t *dst = &__heap_start__;

  while (dst < &__heap_end__)
  {
    *dst++ = (uint32_t)HEAP_MAGIC;
  }
}

static inline void copy_data(void)
{
  register uint32_t *src = &__data_load__;
  register uint32_t *dst = &__data_start__;

  while (dst < &__data_end__)
  {
    *dst++ = *src++;
  }
}

static inline void zero_bss(void)
{
  register uint32_t *dst = &__data_start__;

  while (dst < &__bss_end__)
  {
    *dst++ = 0;
  }
}

static inline void call_static_constructors(void)
{
  register uint32_t i;

  for (i = 0; i < (uint32_t)(__preinit_array_end__ - __preinit_array_start__); i++)
  {
    __preinit_array_start__[i]();
  }

  for (i = 0; i < (uint32_t)(__init_array_end__ - __init_array_start__); i++)
  {
    __init_array_start__[i]();
  }
}

static inline void call_static_destructors(void)
{
  register uint32_t i;

  for (i = 0; i < (uint32_t)(__fini_array_end__ - __fini_array_start__); i++)
  {
    __fini_array_start__[i]();
  }
}

void Reset_Handler(void)
{
  // Set the stack pointer(s)
  // This is done by the hardware reading the value from isr_vectors[0], see
  // "On reset, the processor loads the MSP with the value from address 0x00000000."
  // The PSP has to be set by hand
  set_msp((uint32_t)&__stack_top);
  set_psp((uint32_t)&__stack_top);

  // Fill the stack with STACK_MAGIC (optional)
  fill_stack();

  // Fill the heap with HEAP_MAGIC (optional)
  fill_heap();

  // Copy .data from FLASH to RAM
  copy_data();

  // Zero out .bss
  zero_bss();

  // Call static constructors (C++)
  call_static_constructors();

  (void)main();

  // Call static destructors (C++)
  call_static_destructors();

  while(1)
  {
    // Hang here (we should never get here...)
  };
}
