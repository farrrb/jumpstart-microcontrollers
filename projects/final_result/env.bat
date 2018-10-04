@echo off

rem System Path Configuration
set CMAKE_BIN_PATH=C:\tools\cmake-3.12.3-win64-x64\bin
set NINJA_BIN_PATH=C:\tools\ninja
set ARMCC_BIN_PATH=C:\tools\gcc-arm-none-eabi-7-2018-q2-update-win32\bin
set OPOCD_BIN_PATH=C:\tools\openocd-0.10.0\bin-x64

rem Prepend our paths to system path, so that they will be searched first
set PATH=%CMAKE_BIN_PATH%;%ARMCC_BIN_PATH%;%OPOCD_BIN_PATH%;%PATH%

echo Development Environment: CMake, Ninja, arm-none-eabi-gcc and OpenOCD

rem Open a shell in the current working directory
cmd /K cd %~dp0
