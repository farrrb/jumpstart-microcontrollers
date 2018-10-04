@echo off

mkdir build
cd build
cmd /K cmake -DCMAKE_TOOLCHAIN_FILE=../../../cmake/arm-none-eabi-gcc.cmake -G "Ninja" ..
