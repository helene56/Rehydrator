# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.0)
set(toolchainVersion 13_3_Rel1)
set(picotoolVersion 2.1.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(Rehydrator C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

add_executable(Rehydrator src/main.cpp )

pico_set_program_name(Rehydrator "Rehydrator")
pico_set_program_version(Rehydrator "0.1")

# Modify the below lines to enable/disable output over UART/USB
pico_enable_stdio_uart(Rehydrator 0)
pico_enable_stdio_usb(Rehydrator 1)

# Add the standard library to the build
target_link_libraries(Rehydrator
        pico_stdlib
        hardware_pio  # This links the PIO library
        hardware_adc
        )

# Add the standard include files to the build
target_include_directories(Rehydrator PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}
  ${CMAKE_CURRENT_LIST_DIR}/include
)

# Add your .cpp files to the list of source files
target_sources(Rehydrator PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/src/hydrator.cpp
)

# Compile the PIO program
pico_generate_pio_header(Rehydrator ${CMAKE_CURRENT_LIST_DIR}/src/rgbLed.pio)

pico_add_extra_outputs(Rehydrator)

