cmake_minimum_required(VERSION 3.5)

# Define settings for the project
set(PROJECT_NAME CPP_TP1)     # Change this to your project name
set(PROJECT_VERSION 1.0)      # Change this to the version of your project
set(EXECUTABLE_EXTENTION )    # Change this to the extension of the executable file (e.g. .exe for Windows)
set(INCLUDE_DIR include)      # Change this to the directory where your header files are located
set(SOURCE_DIR src)           # Change this to the directory where your source files are located
set(TEST_DIR test)            # Change this to the directory where your test files are located
set(DEBUG_COMPILE_OPTIONS -Wall)                                    # Change this to the compile options you want to use for Debug configuration
set(RELEASE_COMPILE_OPTIONS -O3 -Wall -Wextra -Wpedantic -Werror)   # Change this to the compile options you want to use for Release configuration
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)         # Change this to the directory where you want the executable to be built

# Project name and version
project(${PROJECT_NAME} VERSION ${PROJECT_VERSION})

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Collect all header and source files
file(GLOB_RECURSE HEADER_FILES ${INCLUDE_DIR}/*.h ${INCLUDE_DIR}/*.hpp)
file(GLOB_RECURSE SOURCE_FILES ${SOURCE_DIR}/*.cpp ${SOURCE_DIR}/*.c)

# Add the executable
add_executable(${PROJECT_NAME}${EXECUTABLE_EXTENTION} ${SOURCE_FILES})

# Add the include directories
target_include_directories(${PROJECT_NAME}${EXECUTABLE_EXTENTION} PUBLIC ${INCLUDE_DIR})

# Set build types if not specified
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

# Define compile options for Debug and Release configurations
target_compile_options(${PROJECT_NAME}${EXECUTABLE_EXTENTION} PRIVATE
  $<$<CONFIG:Debug>:-g ${DEBUG_COMPILE_OPTIONS}>
  $<$<CONFIG:Release>:${RELEASE_COMPILE_OPTIONS}>
)

# Add other necessary directories or libraries here
# target_link_libraries(${PROJECT_NAME} PRIVATE some_library) # Example: linking to a library
# target_link_libraries(${PROJECT_NAME} PUBLIC some_library) # Example: linking to a library
# target_link_libraries(${PROJECT_NAME} INTERFACE some_library) # Example: linking to a library

# Enable testing
enable_testing()

# Set GoogleTest options
set(gtest_build_samples OFF CACHE BOOL "Disable GTest samples" FORCE)
set(BUILD_GMOCK OFF CACHE BOOL "Disable Google Mock" FORCE)

# Add GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/main.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Collect all test source files
file(GLOB_RECURSE TEST_FILES ${TEST_DIR}/*.cpp)

# Add a library for the main project
add_library(${PROJECT_NAME}_lib ${SOURCE_FILES} ${HEADER_FILES})

# Add the include directories for the library
target_include_directories(${PROJECT_NAME}_lib PUBLIC ${INCLUDE_DIR})

# Link the test executables to the main project library
foreach(TEST_FILE ${TEST_FILES})
  get_filename_component(TEST_NAME ${TEST_FILE} NAME_WE)
  add_executable(test_${TEST_NAME} ${TEST_FILE})
  target_link_libraries(test_${TEST_NAME} gtest_main ${PROJECT_NAME}_lib)
  target_include_directories(test_${TEST_NAME} PUBLIC ${INCLUDE_DIR})
  target_compile_options(test_${TEST_NAME} PRIVATE
    $<$<CONFIG:Debug>:-g ${DEBUG_COMPILE_OPTIONS}>
    $<$<CONFIG:Release>:${RELEASE_COMPILE_OPTIONS}>
  )
  add_test(NAME test_${TEST_NAME} COMMAND test_${TEST_NAME} --gtest_color=yes)
endforeach()