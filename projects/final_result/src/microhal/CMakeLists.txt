add_library(microhal STATIC delay.c timer.c)

target_include_directories(microhal PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
