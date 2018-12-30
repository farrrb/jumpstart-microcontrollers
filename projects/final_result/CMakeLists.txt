cmake_minimum_required(VERSION 3.10)

project(final_result)

# Output Directory (for all kinds of output: *.elf, *.hex, ...)
set(OUTPUT_DIRECTORY                ${CMAKE_CURRENT_SOURCE_DIR}/out)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${OUTPUT_DIRECTORY})

# Compiler Configuration
set(CMAKE_C_FLAGS           "-mcpu=cortex-m0 -mthumb -O1 -std=gnu11 -Wall -Wextra -g")
set(CMAKE_C_FLAGS_DEBUG     "")
set(CMAKE_C_FLAGS_RELEASE   "")

# Linker Configuration
set(LINKER_SCRIPT           "${CMAKE_CURRENT_SOURCE_DIR}/src/ld/NRF51822_QFAA_R.ld")
set(CMAKE_EXE_LINKER_FLAGS  "-nostartfiles -nostdlib -Wl,--gc-sections -Wl,-Map=${OUTPUT_DIRECTORY}/${PROJECT_NAME}.map -T ${LINKER_SCRIPT}")

# Create Executable (*.elf)
add_executable(${PROJECT_NAME}.elf
  src/startup/isr_vectors.c
  src/startup/stack.c
  src/startup/heap.c
  src/startup/startup.c
  src/application/main.c
  src/application/display.c
)

# Add Libraries
add_subdirectory(src/microhal)

# Link Libraries (link against libgcc for software division)
target_link_libraries(${PROJECT_NAME}.elf microhal gcc)

# Post-Build Steps
add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD COMMAND ${CMAKE_OBJCOPY} -O ihex ${OUTPUT_DIRECTORY}/${PROJECT_NAME}.elf ${OUTPUT_DIRECTORY}/${PROJECT_NAME}.hex)
add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD COMMAND ${CMAKE_OBJDUMP} -S ${OUTPUT_DIRECTORY}/${PROJECT_NAME}.elf > ${OUTPUT_DIRECTORY}/${PROJECT_NAME}.lst)
