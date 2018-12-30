#include <stdint.h>

#include "delay.h"
#include "timer.h"

#include "display.h"

#define BLINK_TICKS (16384)
#define DELAY_TICKS (10)

// Test Variables
const uint32_t const_data = 0xADDE; // -> .rodata (FLASH)
uint32_t initialized_data = 0xFECA; // -> .data   (RAM)
uint32_t uninitialized_data;        // -> COMMON  (RAM)
uint32_t zero_data = 0;             // -> .bss    (RAM)

uint32_t timer_value = 0;

void draw_heart(void)
{
  display_set_pixel(0, 1);
  display_set_pixel(0, 3);

  display_set_pixel(1, 0);
  display_set_pixel(1, 2);
  display_set_pixel(1, 4);

  display_set_pixel(2, 0);
  display_set_pixel(2, 4);

  display_set_pixel(3, 1);
  display_set_pixel(3, 3);

  display_set_pixel(4, 2);
}

// The One and Only Main Function
int main(void)
{
  uint32_t ctr = 0;

  // initialize timer
  timer_init(TIMER_CH_0);
  timer_start(TIMER_CH_0);

  // initialize display
  display_init();
  draw_heart();

  while (1)
  {
    // update the display
    display_update(DELAY_TICKS);

#if BLINK_TICKS > 0
    // blink
    ctr++;
    if (ctr > BLINK_TICKS)
    {
      display_clear();
    }
    if (ctr > (2 * BLINK_TICKS))
    {
      draw_heart();
      ctr = 0;
    }
#endif

    timer_value = timer_ticks2microseconds(timer_capture(TIMER_CH_0));
    timer_clear(TIMER_CH_0);
  }

  return 0;
}
