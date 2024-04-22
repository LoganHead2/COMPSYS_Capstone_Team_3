cmake_minimum_required(VERSION 3.13)

# Include the Pico SDK
include(pico_sdk_import.cmake)

# Set up the project
project(test_project C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialize the Pico SDK
pico_sdk_init()

# Create the executable
add_executable(test_wifi 
    main.c
)

# Enable USB and UART output
pico_enable_stdio_usb(test_wifi 1)
pico_enable_stdio_uart(test_wifi 0)

# Generate extra outputs (map, hex, bin, etc.)
pico_add_extra_outputs(test_wifi)

# Include directories
target_include_directories(test_wifi PRIVATE 
    ${CMAKE_CURRENT_LIST_DIR}
    ${CMAKE_CURRENT_LIST_DIR}/.. # for our common lwipopts 
)




# Link with necessary libraries
target_link_libraries(test_wifi 
    pico_cyw43_arch_lwip_threadsafe_background 
    pico_stdlib
)










