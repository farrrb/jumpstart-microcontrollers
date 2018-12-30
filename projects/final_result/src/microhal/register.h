///< Register Access (read, write)

#ifndef REGISTER_H__
#define REGISTER_H__

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
