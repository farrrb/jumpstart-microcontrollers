#include "timer.h"

#include "register.h"

void timer_init(timer_channel_t channel)
{
  (void)channel;

  register_write(TIMER0_BASE + TIMER_OFFSET_MODE,      0); // Timer mode
  register_write(TIMER0_BASE + TIMER_OFFSET_BITMODE,   3); // 32-bit
  register_write(TIMER0_BASE + TIMER_OFFSET_PRESCALER, 0); // 16 MHz timer clock
}

void timer_start(timer_channel_t channel)
{
  (void)channel;

  register_write(TIMER0_BASE + TIMER_OFFSET_START,     1);
}

void timer_stop(timer_channel_t channel)
{
  (void)channel;

  register_write(TIMER0_BASE + TIMER_OFFSET_STOP,      1);
}

void timer_clear(timer_channel_t channel)
{
  (void)channel;

  register_write(TIMER0_BASE + TIMER_OFFSET_CLEAR,     1);
}

uint32_t timer_capture(timer_channel_t channel)
{
  (void)channel;

  register_write(TIMER0_BASE + TIMER_OFFSET_CAPTURE0,  1);

  return register_read(TIMER0_BASE + TIMER_OFFSET_CC0);
}

uint32_t timer_ticks2microseconds(uint32_t ticks)
{
  return ticks >> 4;
}
