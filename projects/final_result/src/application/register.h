///< Register Access (read, write)

#ifndef REGISTER_H
#define REGISTER_H

#include <stdint.h>

static inline void register_write(uint32_t addr, uint32_t val)
{
  *((volatile uint32_t *)addr) = val;
}

static inline uint32_t register_read(uint32_t addr)
{
  return *((volatile uint32_t *)addr);
}

#endif
