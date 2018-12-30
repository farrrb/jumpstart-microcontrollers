///< Display Abstraction

#ifndef DISPLAY_H__
#define DISPLAY_H__

#include <stdint.h>

void display_init(void);
void display_clear(void);

void display_update(uint32_t delay_ticks);

void display_set_pixel(uint8_t x, uint8_t y);
void display_clr_pixel(uint8_t x, uint8_t y);

#endif
