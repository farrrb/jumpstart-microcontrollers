#ifndef GPIO_H__
#define GPIO_H__

#define GPIO_BASE             0x50000000  ///< GPIO Port

#define GPIO_OFFSET_OUTSET    0x508       ///< Set individual bits in GPIO port
#define GPIO_OFFSET_OUTCLR    0x50C       ///< Clear individual bits in GPIO port
#define GPIO_OFFSET_DIRSET    0x518       ///< DIR set register

#define GPIO_REG_OUTSET       (GPIO_BASE + GPIO_OFFSET_OUTSET)
#define GPIO_REG_OUTCLR       (GPIO_BASE + GPIO_OFFSET_OUTCLR)
#define GPIO_REG_DIRSET       (GPIO_BASE + GPIO_OFFSET_DIRSET)

#endif
