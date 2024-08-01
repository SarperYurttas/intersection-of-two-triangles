cmake_minimum_required(VERSION 3.10)
project(two_triangles)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the source files
set(SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/utils.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/vector3.cpp
)

# Add the include directories
set(INCLUDE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Include directories
include_directories(${INCLUDE_DIRS})

# Add the executable
add_executable(${PROJECT_NAME} ${SRCS})

# Link the libraries
target_link_libraries(${PROJECT_NAME})
