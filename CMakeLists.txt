cmake_minimum_required(VERSION 3.14)
project(Cpp-Project LANGUAGES CXX)

# Use c++17 or newer
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set output folders
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib) # For *.a or *.lib
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib) # For *.so or *.dll
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin) # For executables

# Use Intel's compiler for C++ if found
find_program(ICPX_PATH icpx)
if(NOT ICPX_PATH)
    message(FATAL_ERROR "Intel icx compiler not found! Did you run source setvars.sh?")
endif()
set(CMAKE_CXX_COMPILER ${ICPX_PATH})

# Inlcude folders
include_directories(
    $ENV{MKLROOT}/include
    ${PROJECT_SOURCE_DIR}/inc
)

# Create STATIC library from my src files
file(GLOB_RECURSE SRC_FILES src/*.cpp)
add_library(Cpp-Project_lib STATIC
    # src/main.cpp 
    ${SRC_FILES}
    #add the extra files from src (main.cpp is just a placeholder for now)
)

# Link Intel's MKL
set(MKL_LIBS "-lmkl_intel_lp64 -lmkl_sequential -lmkl_core -lpthread -lm -ldl")

# Add main executable
# add_executable(main_exec
#     src/main.cpp
# )
# target_link_libraries(main_exec Cpp-Project_lib ${MKL_LIBS})

# Automatically add test executables
file(GLOB TEST_FILES tests/*.cpp)
# Loop through each test file to create separate executables
foreach(TEST_FILE ${TEST_FILES})
    get_filename_component(TEST_NAME ${TEST_FILE} NAME_WE)

    add_executable(${TEST_NAME} ${TEST_FILE})

    target_link_libraries(${TEST_NAME} Cpp-Project_lib ${MKL_LIBS})
endforeach()
