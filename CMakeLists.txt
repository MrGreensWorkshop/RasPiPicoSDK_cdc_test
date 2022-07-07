# What CMake to start at
cmake_minimum_required(VERSION 3.12)
 
# Include the subsidiary .cmake file to get the SDK
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)
 
# Set the name and version of the project
project(PicoTest VERSION 1.0.0)

# Initalise the SDK
pico_sdk_init()

set(sources 
    src/main.c
    )
            
# Create executable with specified sources
add_executable(PicoTest ${sources})
 
# Link the Project to an extra library (pico_stdlib)
target_link_libraries(PicoTest pico_stdlib)
 
# Enable USB CDC
pico_enable_stdio_usb(PicoTest 1)

# Disable UART
pico_enable_stdio_uart(PicoTest 0)
 
# Enable extra outputs (bins)
pico_add_extra_outputs(PicoTest)