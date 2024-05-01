cmake_minimum_required(VERSION 3.13)

# Include the Pico SDK
include(pico_sdk_import.cmake)

# Set up the project
project(test_project C CXX ASM)
set(PICO_SDK_FETCH_FROM_GIT ON)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialize the Pico SDK
pico_sdk_init()

# Create the executable
add_executable(test_adc 
    main.c
)

# Enable USB and UART output
pico_enable_stdio_usb(test_adc 1)
pico_enable_stdio_uart(test_adc 0)

# Generate extra outputs (map, hex, bin, etc.)
pico_add_extra_outputs(test_adc)

# Include directories
target_include_directories(test_adc PRIVATE 
    ${CMAKE_CURRENT_LIST_DIR}
    ${CMAKE_CURRENT_LIST_DIR}/.. # for our common lwipopts 
)




# Link with necessary libraries
target_link_libraries(test_adc 
    pico_cyw43_arch_lwip_threadsafe_background 
    pico_stdlib
    hardware_adc
    hardware_gpio
)










