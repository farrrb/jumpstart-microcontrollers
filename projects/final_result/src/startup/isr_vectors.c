/// Interrupt Vector Table

#include <stdint.h>
#include <stddef.h>

#include "isr_vectors.h"

__attribute__ ((weak, alias ("Default_Handler"))) void NMI_Handler(void);
__attribute__ ((weak, alias ("Default_Handler"))) void HardFault_Handler(void);
__attribute__ ((weak, alias ("Default_Handler"))) void SVC_Handler(void);
__attribute__ ((weak, alias ("Default_Handler"))) void PendSV_Handler(void);
__attribute__ ((weak, alias ("Default_Handler"))) void SysTick_Handler(void);

__attribute__ ((weak, alias ("Default_Handler"))) void POWER_CLOCK_IRQHandler(void);
__attribute__ ((weak, alias ("Default_Handler"))) void RADIO_IRQHandler(void);
__attribute__ ((weak, alias ("Default_Handler"))) void UART0_IRQHandler(void);
__attribute__ ((weak, alias ("Default_Handler"))) void SPI0_TWI0_IRQHandler(void);
__attribute__ ((weak, alias ("Default_Handler"))) void SPI1_TWI1_IRQHandler(void);
__attribute__ ((weak, alias ("Default_Handler"))) void GPIOTE_IRQHandler(void);
__attribute__ ((weak, alias ("Default_Handler"))) void ADC_IRQHandler(void);
__attribute__ ((weak, alias ("Default_Handler"))) void TIMER0_IRQHandler(void);
__attribute__ ((weak, alias ("Default_Handler"))) void TIMER1_IRQHandler(void);
__attribute__ ((weak, alias ("Default_Handler"))) void TIMER2_IRQHandler(void);
__attribute__ ((weak, alias ("Default_Handler"))) void RTC0_IRQHandler(void);
__attribute__ ((weak, alias ("Default_Handler"))) void TEMP_IRQHandler(void);
__attribute__ ((weak, alias ("Default_Handler"))) void RNG_IRQHandler(void);
__attribute__ ((weak, alias ("Default_Handler"))) void ECB_IRQHandler(void);
__attribute__ ((weak, alias ("Default_Handler"))) void CCM_AAR_IRQHandler(void);
__attribute__ ((weak, alias ("Default_Handler"))) void WDT_IRQHandler(void);
__attribute__ ((weak, alias ("Default_Handler"))) void RTC1_IRQHandler(void);
__attribute__ ((weak, alias ("Default_Handler"))) void QDEC_IRQHandler(void);
__attribute__ ((weak, alias ("Default_Handler"))) void LPCOMP_IRQHandler(void);
__attribute__ ((weak, alias ("Default_Handler"))) void SWI0_IRQHandler(void);
__attribute__ ((weak, alias ("Default_Handler"))) void SWI1_IRQHandler(void);
__attribute__ ((weak, alias ("Default_Handler"))) void SWI2_IRQHandler(void);
__attribute__ ((weak, alias ("Default_Handler"))) void SWI3_IRQHandler(void);
__attribute__ ((weak, alias ("Default_Handler"))) void SWI4_IRQHandler(void);
__attribute__ ((weak, alias ("Default_Handler"))) void SWI5_IRQHandler(void);

__attribute__ ((weak)) void Default_Handler(void)
{
  while (1);
}

typedef void (*SystemHandler_t)(void);

// The Interrupt Vector Table
static const SystemHandler_t __isr_vectors[] __attribute__((used, section(".isr_vectors"))) =
{
  // System Handler / Trap Handler
  Reset_Handler,            // Reset Handler
  NMI_Handler,              // NMI Handler
  HardFault_Handler,        // Hard Fault Handler
  NULL,                     // Reserved
  NULL,                     // Reserved
  NULL,                     // Reserved
  NULL,                     // Reserved
  NULL,                     // Reserved
  NULL,                     // Reserved
  NULL,                     // Reserved
  SVC_Handler,              // SVCall Handler
  NULL,                     // Reserved
  NULL,                     // Reserved
  PendSV_Handler,           // PendSV Handler
  SysTick_Handler,          // SysTick Handler
  // External Interrupts
  POWER_CLOCK_IRQHandler,
  RADIO_IRQHandler,
  UART0_IRQHandler,
  SPI0_TWI0_IRQHandler,
  SPI1_TWI1_IRQHandler,
  NULL,                     // Reserved
  GPIOTE_IRQHandler,
  ADC_IRQHandler,
  TIMER0_IRQHandler,
  TIMER1_IRQHandler,
  TIMER2_IRQHandler,
  RTC0_IRQHandler,
  TEMP_IRQHandler,
  RNG_IRQHandler,
  ECB_IRQHandler,
  CCM_AAR_IRQHandler,
  WDT_IRQHandler,
  RTC1_IRQHandler,
  QDEC_IRQHandler,
  LPCOMP_IRQHandler,
  SWI0_IRQHandler,
  SWI1_IRQHandler,
  SWI2_IRQHandler,
  SWI3_IRQHandler,
  SWI4_IRQHandler,
  SWI5_IRQHandler,
  NULL,                     // Reserved
  NULL,                     // Reserved
  NULL,                     // Reserved
  NULL,                     // Reserved
  NULL,                     // Reserved
  NULL                      // Reserved
};
