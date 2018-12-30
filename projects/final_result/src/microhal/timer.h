#ifndef TIMER_H__
#define TIMER_H__

#include <stdint.h>

#define TIMER0_BASE             0x40008000    ///< TIMER TIMER0 Timer/Counter
#define TIMER1_BASE             0x40009000    ///< TIMER TIMER1 Timer/Counter
#define TIMER2_BASE             0x4000A000    ///< TIMER TIMER2 Timer/Counter

#define TIMER_OFFSET_START      0x000         ///< Start Timer
#define TIMER_OFFSET_STOP       0x004         ///< Stop Timer
#define TIMER_OFFSET_COUNT      0x008         ///< Increment Timer (Counter mode only)
#define TIMER_OFFSET_CLEAR      0x00C         ///< Clear time
#define TIMER_OFFSET_SHUTDOWN   0x010         ///< Shut down timer
#define TIMER_OFFSET_CAPTURE0   0x040         ///< Capture Timer value to CC[0] register
#define TIMER_OFFSET_CAPTURE1   0x044         ///< Capture Timer value to CC[1] register
#define TIMER_OFFSET_CAPTURE2   0x048         ///< Capture Timer value to CC[2] register
#define TIMER_OFFSET_CAPTURE3   0x04C         ///< Capture Timer value to CC[3] register18 Timer/counter (TIMER)
#define TIMER_OFFSET_COMPARE0   0x140         ///< Compare event on CC[0] match
#define TIMER_OFFSET_COMPARE1   0x144         ///< Compare event on CC[1] match
#define TIMER_OFFSET_COMPARE2   0x148         ///< Compare event on CC[2] match
#define TIMER_OFFSET_COMPARE3   0x14C         ///< Compare event on CC[3] match
#define TIMER_OFFSET_SHORTS     0x200         ///< Shortcut register
#define TIMER_OFFSET_INTENSET   0x304         ///< Enable interrupt
#define TIMER_OFFSET_INTENCLR   0x308         ///< Disable interrupt
#define TIMER_OFFSET_MODE       0x504         ///< Timer mode selection
#define TIMER_OFFSET_BITMODE    0x508         ///< Configure the number of bits used by the TIMER
#define TIMER_OFFSET_PRESCALER  0x510         ///< Timer prescaler register
#define TIMER_OFFSET_CC0        0x540         ///< Capture/Compare register 0
#define TIMER_OFFSET_CC1        0x544         ///< Capture/Compare register 1
#define TIMER_OFFSET_CC2        0x548         ///< Capture/Compare register 2
#define TIMER_OFFSET_CC3        0x54C         ///< Capture/Compare register 3

#define TIMER_FREQUENCY         ((uint32_t)16000000) ///< Timer frequency in [MHz]

typedef enum
{
  TIMER_CH_0 = 0,
  TIMER_CH_1 = 1,
  TIMER_CH_2 = 2
} timer_channel_t;

void timer_init(timer_channel_t channel);
void timer_start(timer_channel_t channel);
void timer_stop(timer_channel_t channel);
void timer_clear(timer_channel_t channel);
uint32_t timer_capture(timer_channel_t channel);

uint32_t timer_ticks2microseconds(uint32_t ticks);

#endif
