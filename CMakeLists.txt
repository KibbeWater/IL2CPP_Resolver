cmake_minimum_required(VERSION 3.15)

# Project name
project(IL2CPP_Resolver C CXX)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Collect all source files
file(GLOB_RECURSE SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

# Add the static library target
add_library(IL2CPP_Resolver STATIC ${SOURCES})

# Add include directories to the target with proper PUBLIC visibility
# This ensures headers are correctly propagated to dependent targets
target_include_directories(IL2CPP_Resolver PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
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

    # Install header files from include directory with proper directory structure
    install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
        DESTINATION include
        FILES_MATCHING 
        PATTERN "*.h"
        PATTERN "*.hpp"
    )

    # Create a package configuration file
    configure_package_config_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/cmake/IL2CPP_ResolverConfig.cmake.in
        ${CMAKE_CURRENT_BINARY_DIR}/IL2CPP_ResolverConfig.cmake
        INSTALL_DESTINATION lib/cmake/IL2CPP_Resolver
    )

    # Install the package configuration file
    install(FILES ${CMAKE_CURRENT_BINARY_DIR}/IL2CPP_ResolverConfig.cmake
        DESTINATION lib/cmake/IL2CPP_Resolver
    )

    # Export the package configuration
    export(EXPORT IL2CPP_ResolverTargets
        FILE ${CMAKE_CURRENT_BINARY_DIR}/IL2CPP_ResolverTargets.cmake
        NAMESPACE IL2CPP_Resolver::
    )
endif()