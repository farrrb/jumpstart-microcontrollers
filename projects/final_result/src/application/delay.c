#include "delay.h"

static uint32_t delay_ticks = 0;

void delay(uint32_t ticks)
{
  uint32_t i;
  for(i = 0; i < ticks; i++)
  {
    delay_ticks++;
  }
}
