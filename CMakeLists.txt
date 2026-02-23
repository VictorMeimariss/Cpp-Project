cmake_minimum_required(VERSION 3.14)

# Use Intel's compiler for C++ if found
find_program(ICPX_PATH icpx)
if(ICPX_PATH)
    message(STATUS "Intel icpx found. Using: ${ICPX_PATH} for C++ compilation")
    set(CMAKE_CXX_COMPILER ${ICPX_PATH})
    set(MKL_INTERFACE_LAYER "-lmkl_intel_lp64")
else()
    message(STATUS "Intel icx compiler not found! (Did you run source setvars.sh?) Falling back to default system compiler.")
    set(MKL_INTERFACE_LAYER "-lmkl_gf_lp64")
endif()

# Use Intel's compiler for C
find_program(ICX_PATH icx)
if (ICX_PATH)
    message(STATUS "Intel icx found. Using: ${ICX_PATH} for C compilation")
    set(CMAKE_C_COMPILER ${ICX_PATH})
endif()


project(Cpp-Project LANGUAGES C CXX)

# Use C++17 or newer
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set output folders
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib) # For *.a or *.lib
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib) # For *.so or *.dll
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin) # For executables

# Inlcude folders
include_directories(
    $ENV{MKLROOT}/include
    ${PROJECT_SOURCE_DIR}/inc
)

# Create STATIC library from my src files
file(GLOB_RECURSE SRC_FILES src/*.cpp src/*.c)
add_library(Cpp-Project_lib STATIC
    ${SRC_FILES}
    #adds the files from src automatically
)

# Link Intel's MKL
set(MKL_LIBS "-lmkl_intel_lp64 -lmkl_sequential -lmkl_core -lpthread -lm -ldl")

# Automatically add test executables
file(GLOB TEST_FILES tests/*.cpp)
# Loop through each test file to create separate executables
foreach(TEST_FILE ${TEST_FILES})
    get_filename_component(TEST_NAME ${TEST_FILE} NAME_WE)

    add_executable(${TEST_NAME} ${TEST_FILE})

    target_link_libraries(${TEST_NAME} Cpp-Project_lib ${MKL_LIBS})
endforeach()

# Install the lib into /usr/local/lib
install(
    TARGETS Cpp-Project_lib
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
)

# Install the headers to /usr/local/include
install(
    DIRECTORY inc/
    DESTINATION include/CppProject
)
