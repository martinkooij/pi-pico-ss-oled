# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(oled_example C CXX ASM)

pico_sdk_init()

# Add executable. Default name is the project name, 
add_executable(oled_example ss_oled_demo.cpp)
add_subdirectory(../pico-ss-oled build)

pico_add_extra_outputs(oled_example)
target_link_libraries(oled_example pico_stdlib pico_ss_oled)
