cmake_minimum_required(VERSION 3.15)

# Project name
project(IL2CPP_Resolver)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add include directories
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/API
    ${CMAKE_CURRENT_SOURCE_DIR}/Unity
    ${CMAKE_CURRENT_SOURCE_DIR}/Structures
    ${CMAKE_CURRENT_SOURCE_DIR}/Utils
)

# Collect all source files
file(GLOB_RECURSE SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp
)

# Add the static library target
add_library(IL2CPP_Resolver STATIC ${SOURCES})

# Define the installation rules
install(TARGETS IL2CPP_Resolver
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)

# Install header files
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/
    DESTINATION include/IL2CPP_Resolver
    FILES_MATCHING PATTERN "*.hpp"
)