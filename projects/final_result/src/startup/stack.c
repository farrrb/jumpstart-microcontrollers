// Stack

#include <stdint.h>

#include "startup_config.h"

#include "linker_symbols.h"

// Stack Pointer
static void * __stack_pointer __attribute__((used, section(".stack_pointer"))) = (void *)&__stack_top;

// Reserve Stack Space
static uint8_t __stack_storage[STACK_SIZE] __attribute__((aligned(8), used, section(".stack")));
