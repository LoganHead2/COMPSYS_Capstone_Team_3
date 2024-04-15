﻿# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.29

# compile ASM with C:/Program Files (x86)/Arm GNU Toolchain arm-none-eabi/13.2 Rel1/bin/arm-none-eabi-gcc.exe
# compile C with C:/Program Files (x86)/Arm GNU Toolchain arm-none-eabi/13.2 Rel1/bin/arm-none-eabi-gcc.exe
# compile CXX with C:/Program Files (x86)/Arm GNU Toolchain arm-none-eabi/13.2 Rel1/bin/arm-none-eabi-g++.exe
ASM_DEFINES = -DCFG_TUSB_MCU=OPT_MCU_RP2040 -DCFG_TUSB_OS=OPT_OS_PICO -DCYW43_LWIP=1 -DLIB_PICO_ASYNC_CONTEXT_THREADSAFE_BACKGROUND=1 -DLIB_PICO_BIT_OPS=1 -DLIB_PICO_BIT_OPS_PICO=1 -DLIB_PICO_CYW43_ARCH=1 -DLIB_PICO_DIVIDER=1 -DLIB_PICO_DIVIDER_HARDWARE=1 -DLIB_PICO_DOUBLE=1 -DLIB_PICO_DOUBLE_PICO=1 -DLIB_PICO_FIX_RP2040_USB_DEVICE_ENUMERATION=1 -DLIB_PICO_FLOAT=1 -DLIB_PICO_FLOAT_PICO=1 -DLIB_PICO_INT64_OPS=1 -DLIB_PICO_INT64_OPS_PICO=1 -DLIB_PICO_MALLOC=1 -DLIB_PICO_MEM_OPS=1 -DLIB_PICO_MEM_OPS_PICO=1 -DLIB_PICO_PLATFORM=1 -DLIB_PICO_PRINTF=1 -DLIB_PICO_PRINTF_PICO=1 -DLIB_PICO_RAND=1 -DLIB_PICO_RUNTIME=1 -DLIB_PICO_STANDARD_LINK=1 -DLIB_PICO_STDIO=1 -DLIB_PICO_STDIO_USB=1 -DLIB_PICO_STDLIB=1 -DLIB_PICO_SYNC=1 -DLIB_PICO_SYNC_CRITICAL_SECTION=1 -DLIB_PICO_SYNC_MUTEX=1 -DLIB_PICO_SYNC_SEM=1 -DLIB_PICO_TIME=1 -DLIB_PICO_UNIQUE_ID=1 -DLIB_PICO_UTIL=1 -DPICO_BOARD=\"pico_w\" -DPICO_BUILD=1 -DPICO_CMAKE_BUILD_TYPE=\"Release\" -DPICO_COPY_TO_RAM=0 -DPICO_CXX_ENABLE_EXCEPTIONS=0 -DPICO_CYW43_ARCH_THREADSAFE_BACKGROUND=1 -DPICO_NO_FLASH=0 -DPICO_NO_HARDWARE=0 -DPICO_ON_DEVICE=1 -DPICO_RP2040_USB_DEVICE_UFRAME_FIX=1 -DPICO_TARGET_NAME=\"test\" -DPICO_USE_BLOCKED_RAM=0

ASM_INCLUDES = -IC:\Y4S1\CS770\TeamCS\example\Testing_wirless -IC:\Y4S1\CS770\TeamCS\example\Testing_wirless\.. -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\pico_async_context\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\pico_platform\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2040\hardware_regs\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\hardware_base\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\common\pico_base\include -IC:\Y4S1\CS770\TeamCS\example\Testing_wirless\build\generated\pico_base -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\boards\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\pico_lwip\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\pico_rand\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\pico_unique_id\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\hardware_flash\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2040\hardware_structs\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\hardware_claim\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\hardware_sync\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\pico_bootrom\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\hardware_clocks\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\hardware_gpio\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\hardware_irq\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\common\pico_sync\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\common\pico_time\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\hardware_timer\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\common\pico_util\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\hardware_resets\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\hardware_pll\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\hardware_vreg\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\hardware_watchdog\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\hardware_xosc\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\lib\lwip\src\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\pico_cyw43_arch\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\lib\cyw43-driver\src -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\lib\cyw43-driver\firmware -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\pico_cyw43_driver\cybt_shared_bus -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\hardware_pio\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\hardware_dma\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\hardware_exception\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\pico_cyw43_driver\include -IC:\Y4S1\CS770\TeamCS\example\Testing_wirless\build\pico-sdk\src\rp2_common\pico_cyw43_driver -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\common\pico_stdlib\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\hardware_uart\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\hardware_divider\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\pico_runtime\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\pico_printf\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\common\pico_bit_ops\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\common\pico_divider\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\pico_double\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\pico_float\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\pico_malloc\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\common\pico_binary_info\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\pico_stdio\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\pico_stdio_usb\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\common\pico_usb_reset_interface\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\pico_int64_ops\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\pico_mem_ops\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\boot_stage2\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\lib\tinyusb\src -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\lib\tinyusb\src\common -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\lib\tinyusb\hw -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\pico_fix\rp2040_usb_device_enumeration\include

ASM_FLAGS = -mcpu=cortex-m0plus -mthumb -O3 -DNDEBUG -ffunction-sections -fdata-sections

C_DEFINES = -DCFG_TUSB_MCU=OPT_MCU_RP2040 -DCFG_TUSB_OS=OPT_OS_PICO -DCYW43_LWIP=1 -DLIB_PICO_ASYNC_CONTEXT_THREADSAFE_BACKGROUND=1 -DLIB_PICO_BIT_OPS=1 -DLIB_PICO_BIT_OPS_PICO=1 -DLIB_PICO_CYW43_ARCH=1 -DLIB_PICO_DIVIDER=1 -DLIB_PICO_DIVIDER_HARDWARE=1 -DLIB_PICO_DOUBLE=1 -DLIB_PICO_DOUBLE_PICO=1 -DLIB_PICO_FIX_RP2040_USB_DEVICE_ENUMERATION=1 -DLIB_PICO_FLOAT=1 -DLIB_PICO_FLOAT_PICO=1 -DLIB_PICO_INT64_OPS=1 -DLIB_PICO_INT64_OPS_PICO=1 -DLIB_PICO_MALLOC=1 -DLIB_PICO_MEM_OPS=1 -DLIB_PICO_MEM_OPS_PICO=1 -DLIB_PICO_PLATFORM=1 -DLIB_PICO_PRINTF=1 -DLIB_PICO_PRINTF_PICO=1 -DLIB_PICO_RAND=1 -DLIB_PICO_RUNTIME=1 -DLIB_PICO_STANDARD_LINK=1 -DLIB_PICO_STDIO=1 -DLIB_PICO_STDIO_USB=1 -DLIB_PICO_STDLIB=1 -DLIB_PICO_SYNC=1 -DLIB_PICO_SYNC_CRITICAL_SECTION=1 -DLIB_PICO_SYNC_MUTEX=1 -DLIB_PICO_SYNC_SEM=1 -DLIB_PICO_TIME=1 -DLIB_PICO_UNIQUE_ID=1 -DLIB_PICO_UTIL=1 -DPICO_BOARD=\"pico_w\" -DPICO_BUILD=1 -DPICO_CMAKE_BUILD_TYPE=\"Release\" -DPICO_COPY_TO_RAM=0 -DPICO_CXX_ENABLE_EXCEPTIONS=0 -DPICO_CYW43_ARCH_THREADSAFE_BACKGROUND=1 -DPICO_NO_FLASH=0 -DPICO_NO_HARDWARE=0 -DPICO_ON_DEVICE=1 -DPICO_RP2040_USB_DEVICE_UFRAME_FIX=1 -DPICO_TARGET_NAME=\"test\" -DPICO_USE_BLOCKED_RAM=0

C_INCLUDES = -IC:\Y4S1\CS770\TeamCS\example\Testing_wirless -IC:\Y4S1\CS770\TeamCS\example\Testing_wirless\.. -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\pico_async_context\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\pico_platform\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2040\hardware_regs\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\hardware_base\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\common\pico_base\include -IC:\Y4S1\CS770\TeamCS\example\Testing_wirless\build\generated\pico_base -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\boards\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\pico_lwip\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\pico_rand\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\pico_unique_id\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\hardware_flash\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2040\hardware_structs\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\hardware_claim\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\hardware_sync\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\pico_bootrom\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\hardware_clocks\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\hardware_gpio\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\hardware_irq\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\common\pico_sync\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\common\pico_time\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\hardware_timer\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\common\pico_util\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\hardware_resets\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\hardware_pll\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\hardware_vreg\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\hardware_watchdog\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\hardware_xosc\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\lib\lwip\src\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\pico_cyw43_arch\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\lib\cyw43-driver\src -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\lib\cyw43-driver\firmware -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\pico_cyw43_driver\cybt_shared_bus -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\hardware_pio\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\hardware_dma\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\hardware_exception\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\pico_cyw43_driver\include -IC:\Y4S1\CS770\TeamCS\example\Testing_wirless\build\pico-sdk\src\rp2_common\pico_cyw43_driver -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\common\pico_stdlib\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\hardware_uart\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\hardware_divider\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\pico_runtime\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\pico_printf\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\common\pico_bit_ops\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\common\pico_divider\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\pico_double\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\pico_float\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\pico_malloc\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\common\pico_binary_info\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\pico_stdio\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\pico_stdio_usb\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\common\pico_usb_reset_interface\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\pico_int64_ops\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\pico_mem_ops\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\boot_stage2\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\lib\tinyusb\src -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\lib\tinyusb\src\common -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\lib\tinyusb\hw -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\pico_fix\rp2040_usb_device_enumeration\include

C_FLAGS = -mcpu=cortex-m0plus -mthumb -O3 -DNDEBUG -std=gnu11 -ffunction-sections -fdata-sections

CXX_DEFINES = -DCFG_TUSB_MCU=OPT_MCU_RP2040 -DCFG_TUSB_OS=OPT_OS_PICO -DCYW43_LWIP=1 -DLIB_PICO_ASYNC_CONTEXT_THREADSAFE_BACKGROUND=1 -DLIB_PICO_BIT_OPS=1 -DLIB_PICO_BIT_OPS_PICO=1 -DLIB_PICO_CYW43_ARCH=1 -DLIB_PICO_DIVIDER=1 -DLIB_PICO_DIVIDER_HARDWARE=1 -DLIB_PICO_DOUBLE=1 -DLIB_PICO_DOUBLE_PICO=1 -DLIB_PICO_FIX_RP2040_USB_DEVICE_ENUMERATION=1 -DLIB_PICO_FLOAT=1 -DLIB_PICO_FLOAT_PICO=1 -DLIB_PICO_INT64_OPS=1 -DLIB_PICO_INT64_OPS_PICO=1 -DLIB_PICO_MALLOC=1 -DLIB_PICO_MEM_OPS=1 -DLIB_PICO_MEM_OPS_PICO=1 -DLIB_PICO_PLATFORM=1 -DLIB_PICO_PRINTF=1 -DLIB_PICO_PRINTF_PICO=1 -DLIB_PICO_RAND=1 -DLIB_PICO_RUNTIME=1 -DLIB_PICO_STANDARD_LINK=1 -DLIB_PICO_STDIO=1 -DLIB_PICO_STDIO_USB=1 -DLIB_PICO_STDLIB=1 -DLIB_PICO_SYNC=1 -DLIB_PICO_SYNC_CRITICAL_SECTION=1 -DLIB_PICO_SYNC_MUTEX=1 -DLIB_PICO_SYNC_SEM=1 -DLIB_PICO_TIME=1 -DLIB_PICO_UNIQUE_ID=1 -DLIB_PICO_UTIL=1 -DPICO_BOARD=\"pico_w\" -DPICO_BUILD=1 -DPICO_CMAKE_BUILD_TYPE=\"Release\" -DPICO_COPY_TO_RAM=0 -DPICO_CXX_ENABLE_EXCEPTIONS=0 -DPICO_CYW43_ARCH_THREADSAFE_BACKGROUND=1 -DPICO_NO_FLASH=0 -DPICO_NO_HARDWARE=0 -DPICO_ON_DEVICE=1 -DPICO_RP2040_USB_DEVICE_UFRAME_FIX=1 -DPICO_TARGET_NAME=\"test\" -DPICO_USE_BLOCKED_RAM=0

CXX_INCLUDES = -IC:\Y4S1\CS770\TeamCS\example\Testing_wirless -IC:\Y4S1\CS770\TeamCS\example\Testing_wirless\.. -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\pico_async_context\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\pico_platform\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2040\hardware_regs\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\hardware_base\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\common\pico_base\include -IC:\Y4S1\CS770\TeamCS\example\Testing_wirless\build\generated\pico_base -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\boards\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\pico_lwip\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\pico_rand\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\pico_unique_id\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\hardware_flash\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2040\hardware_structs\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\hardware_claim\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\hardware_sync\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\pico_bootrom\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\hardware_clocks\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\hardware_gpio\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\hardware_irq\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\common\pico_sync\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\common\pico_time\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\hardware_timer\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\common\pico_util\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\hardware_resets\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\hardware_pll\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\hardware_vreg\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\hardware_watchdog\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\hardware_xosc\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\lib\lwip\src\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\pico_cyw43_arch\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\lib\cyw43-driver\src -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\lib\cyw43-driver\firmware -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\pico_cyw43_driver\cybt_shared_bus -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\hardware_pio\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\hardware_dma\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\hardware_exception\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\pico_cyw43_driver\include -IC:\Y4S1\CS770\TeamCS\example\Testing_wirless\build\pico-sdk\src\rp2_common\pico_cyw43_driver -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\common\pico_stdlib\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\hardware_uart\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\hardware_divider\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\pico_runtime\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\pico_printf\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\common\pico_bit_ops\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\common\pico_divider\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\pico_double\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\pico_float\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\pico_malloc\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\common\pico_binary_info\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\pico_stdio\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\pico_stdio_usb\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\common\pico_usb_reset_interface\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\pico_int64_ops\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\pico_mem_ops\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\boot_stage2\include -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\lib\tinyusb\src -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\lib\tinyusb\src\common -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\lib\tinyusb\hw -IC:\Y4S1\CS770\TeamCS\example\pico-sdk\src\rp2_common\pico_fix\rp2040_usb_device_enumeration\include

CXX_FLAGS = -mcpu=cortex-m0plus -mthumb -O3 -DNDEBUG -std=gnu++17 -ffunction-sections -fdata-sections -fno-exceptions -fno-unwind-tables -fno-rtti -fno-use-cxa-atexit

