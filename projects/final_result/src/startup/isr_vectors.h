///< Interface Header

#ifndef ISR_VECTORS_H
#define ISR_VECTORS_H

// Startup Code
void Reset_Handler(void);
void Default_Handler(void);

// System Handler / Trap Handler
void NMI_Handler(void);
void HardFault_Handler(void);
void SVC_Handler(void);
void PendSV_Handler(void);
void SysTick_Handler(void);

// External Interrupts
void POWER_CLOCK_IRQHandler(void);
void RADIO_IRQHandler(void);
void UART0_IRQHandler(void);
void SPI0_TWI0_IRQHandler(void);
void SPI1_TWI1_IRQHandler(void);
void GPIOTE_IRQHandler(void);
void ADC_IRQHandler(void);
void TIMER0_IRQHandler(void);
void TIMER1_IRQHandler(void);
void TIMER2_IRQHandler(void);
void RTC0_IRQHandler(void);
void TEMP_IRQHandler(void);
void RNG_IRQHandler(void);
void ECB_IRQHandler(void);
void CCM_AAR_IRQHandler(void);
void WDT_IRQHandler(void);
void RTC1_IRQHandler(void);
void QDEC_IRQHandler(void);
void LPCOMP_IRQHandler(void);
void SWI0_IRQHandler(void);
void SWI1_IRQHandler(void);
void SWI2_IRQHandler(void);
void SWI3_IRQHandler(void);
void SWI4_IRQHandler(void);
void SWI5_IRQHandler(void);

#endif
