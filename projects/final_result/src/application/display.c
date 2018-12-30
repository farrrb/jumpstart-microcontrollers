#include "display.h"

#include "delay.h"
#include "gpio.h"
#include "register.h"

#define ROW_TO_INDEX(row) ((row) >> (13+1))
#define ROW1  (1 << 13)
#define ROW2  (1 << 14)
#define ROW3  (1 << 15)

#define COL1  (1 <<  4)
#define COL2  (1 <<  5)
#define COL3  (1 <<  6)
#define COL4  (1 <<  7)
#define COL5  (1 <<  8)
#define COL6  (1 <<  9)
#define COL7  (1 << 10)
#define COL8  (1 << 11)
#define COL9  (1 << 12)

#define ROWS  (ROW1|ROW2|ROW3)
#define COLS  (COL1|COL2|COL3|COL4|COL5|COL6|COL7|COL8|COL9)

struct Matrix
{
  uint32_t row;
  uint32_t col;
};

const struct Matrix lookup_table[5][5]=
{
  {{ROW1, COL1}, {ROW2, COL4}, {ROW1, COL2}, {ROW2, COL5}, {ROW1, COL3}},
  {{ROW3, COL4}, {ROW3, COL5}, {ROW3, COL6}, {ROW3, COL7}, {ROW3, COL8}},
  {{ROW2, COL2}, {ROW1, COL9}, {ROW2, COL3}, {ROW3, COL9}, {ROW2, COL1}},
  {{ROW1, COL8}, {ROW1, COL7}, {ROW1, COL6}, {ROW1, COL5}, {ROW1, COL4}},
  {{ROW3, COL3}, {ROW2, COL7}, {ROW3, COL1}, {ROW2, COL6}, {ROW3, COL2}}
};

uint32_t led_matrix[3] = {0};

void display_init(void)
{
  // Configure outputs
  // set directions to output on all rows & columns
  register_write(GPIO_REG_DIRSET, (ROWS|COLS));

  // clear screen
  display_clear();
}

void display_clear(void)
{
  uint8_t row;

  // reset internal data
  for (row = 0; row < 3; row++)
  {
    led_matrix[row] = 0;
  }

  // Set all rows low
  // Set all cols high
  register_write(GPIO_REG_OUTCLR, ROWS);
  register_write(GPIO_REG_OUTSET, COLS);
}

void display_update(uint32_t delay_ticks)
{
  // ROW1
  register_write(GPIO_REG_OUTCLR, ROWS);
  register_write(GPIO_REG_OUTSET, COLS);

  register_write(GPIO_REG_OUTCLR, led_matrix[0]);
  register_write(GPIO_REG_OUTSET, ROW1);
  delay(delay_ticks);

  // ROW2
  register_write(GPIO_REG_OUTCLR, ROWS);
  register_write(GPIO_REG_OUTSET, COLS);

  register_write(GPIO_REG_OUTCLR, led_matrix[1]);
  register_write(GPIO_REG_OUTSET, ROW2);
  delay(delay_ticks);

  // ROW3
  register_write(GPIO_REG_OUTCLR, ROWS);
  register_write(GPIO_REG_OUTSET, COLS);

  register_write(GPIO_REG_OUTCLR, led_matrix[2]);
  register_write(GPIO_REG_OUTSET, ROW3);
  delay(delay_ticks);
}

void display_set_pixel(uint8_t x, uint8_t y)
{
  led_matrix[ROW_TO_INDEX(lookup_table[x][y].row)] |= lookup_table[x][y].col;
}

void display_clr_pixel(uint8_t x, uint8_t y)
{
  led_matrix[ROW_TO_INDEX(lookup_table[x][y].row)] &= ~lookup_table[x][y].col;
}
