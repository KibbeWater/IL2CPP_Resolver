cmake_minimum_required(VERSION 3.15)

# Project name
project(IL2CPP_Resolver C CXX)

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

# Add include directories to the target
# This ensures the include directories are available when using FetchContent
target_include_directories(IL2CPP_Resolver PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include/IL2CPP_Resolver>
)

# Explicitly set the language for the target
set_target_properties(IL2CPP_Resolver PROPERTIES LINKER_LANGUAGE CXX)

# Add an option to enable installation during FetchContent builds
option(IL2CPP_RESOLVER_ENABLE_INSTALL "Enable installation of IL2CPP_Resolver during FetchContent builds" ON)

if(IL2CPP_RESOLVER_ENABLE_INSTALL)
    # Ensure the install rules are executed
    include(CMakePackageConfigHelpers)
    install(TARGETS IL2CPP_Resolver
        EXPORT IL2CPP_ResolverTargets
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin
    )

    # Install all header files from the include directory to the correct destination
    install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
        DESTINATION include
        FILES_MATCHING PATTERN "*.h"
    )

    # Install header files from the root source directory that might be missed
    install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/
        DESTINATION include
        FILES_MATCHING PATTERN "*.h"
        PATTERN "include/*" EXCLUDE  # Exclude the include directory to avoid duplicates
    )

    install(
        DIRECTORY include DESTINATION .
    )

    # Export the package configuration
    export(EXPORT IL2CPP_ResolverTargets
        FILE ${CMAKE_CURRENT_BINARY_DIR}/IL2CPP_ResolverTargets.cmake
        NAMESPACE IL2CPP_Resolver::
    )
endif()