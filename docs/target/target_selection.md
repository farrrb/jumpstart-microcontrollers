# Why the BBC Micro Bit (micro:bit)?
There were a lot of factors involved when I chose the platform for this project.

My top five requirements where the following:

1. The target board shall be affordable.
2. The target board shall be available.
3. The target board shall be simple in terms of schematic complexity.
4. The target microcontroller shall be an ARM Cortex-M core.
5. The target platform shall be open in terms of open source.

After a short period of research I found the [BBC Micro Bit](https://microbit.org/) to be the perfect platform for this project, because it fulfilled all of my requirements. For me it seems that the **micro:bit** is the "Raspberry Pi" of MCUs.

# Application MCU Specification
This will be our focus in this book. This is where the magic (application) happens.

- 32-bit [ARM (R) Cortex-M0](https://developer.arm.com/products/processors/cortex-m/cortex-m0) CPU ([Nordic nRF51822-QFAA-R rev 3](https://www.nordicsemi.com/eng/Products/Bluetooth-low-energy/nRF51822))
- 16MHz Clock Speed (Crystal Oscillator)
- 16kByte RAM (SRAM)
- 256kByte ROM (Flash)
- Onboard Bluetooth Low Energy (BLE) peripheral

# Interface MCU Specification
This MCU basically has three functions:

1. It is the responsible for the USB interface and the Debug Access Port of the application MCU (see [DAPLink](https://tech.microbit.org/software/daplink-interface/) for more information).
2. The interface MCU is also responsible for the power supply. It contains the step down regulator to convert the 5V USB voltage to the 3.3V needed by the application MCU. We will use this only as a Debug / Flash Adapter throughout this book.
3. The third function we will use is the UART to USB conversion. With this little functionality it is possible to exchange messages between the application MCU and the PC.

- 32-bit [ARM (R) Cortex-M0+](https://developer.arm.com/products/processors/cortex-m/cortex-m0-plus) CPU ([NXP MKL26Z128VFM4](https://www.nxp.com/part/MKL26Z128VFM4))
- 16MHz Clock Speed (Crystal Oscillator)
- 16kByte RAM (SRAM)
- 128kByte ROM (Flash)

# Board Specification
- 2 User Buttons
- 1 System Reset Button
- 5x5 LED Matrix ("Display")
- 3-Axis Accelerometer ([NXP MMA8653FC](https://www.nxp.com/products/sensors/motion-sensors/accelerometers-for-iot/2g-4g-8g-low-g-10-bit-digital-accelerometer:MMA8653FC))
- Magnetometer ([NXP MAG3110](https://www.nxp.com/products/sensors/magnetic-sensors/magnetometers/high-accuracy-3d-magnetometer:MAG3110))
