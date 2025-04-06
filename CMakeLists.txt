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

# Add private include directories for source files 
target_include_directories(IL2CPP_Resolver PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include/IL2CPP_Resolver
    ${CMAKE_CURRENT_SOURCE_DIR}/include/IL2CPP_Resolver/API
    ${CMAKE_CURRENT_SOURCE_DIR}/include/IL2CPP_Resolver/Unity
    ${CMAKE_CURRENT_SOURCE_DIR}/include/IL2CPP_Resolver/Unity/API
    ${CMAKE_CURRENT_SOURCE_DIR}/include/IL2CPP_Resolver/Unity/Structures
    ${CMAKE_CURRENT_SOURCE_DIR}/include/IL2CPP_Resolver/Utils
)

# Explicitly set the language for the target
set_target_properties(IL2CPP_Resolver PROPERTIES LINKER_LANGUAGE CXX)

# Add namespace alias targets
add_library(IL2CPP_Resolver::IL2CPP_Resolver ALIAS IL2CPP_Resolver)
add_library(resolver::IL2CPP_Resolver ALIAS IL2CPP_Resolver)

# This section allows FetchContent to work with any chosen name
# This block detects if we're being included via FetchContent and creates an alias with that name
if(DEFINED PROJECT_IS_INCLUDED)
    # Nothing specific needed here, the alias is created below
elseif(DEFINED PROJECT_NAME AND NOT PROJECT_NAME STREQUAL IL2CPP_Resolver)
    # We're included in another project, but not via FetchContent
else()
    # Check if we're being consumed via FetchContent
    get_directory_property(parent_dir PARENT_DIRECTORY)
    if(parent_dir)
        get_directory_property(fetch_dirs DIRECTORY "${parent_dir}" VARIABLES)
        foreach(var ${fetch_dirs})
            if("${var}" MATCHES "(.*)_SOURCE_DIR" AND "${${var}}" STREQUAL "${CMAKE_CURRENT_SOURCE_DIR}")
                string(REGEX REPLACE "_SOURCE_DIR$" "" fetch_name "${var}")
                message(STATUS "IL2CPP_Resolver is being included via FetchContent with name: ${fetch_name}")
                
                # Create an alias with the FetchContent name
                message(STATUS "Creating alias: ${fetch_name}::IL2CPP_Resolver")
                add_library(${fetch_name}::IL2CPP_Resolver ALIAS IL2CPP_Resolver)
            endif()
        endforeach()
    endif()
endif()

# Add an option to enable installation during FetchContent builds
option(IL2CPP_RESOLVER_ENABLE_INSTALL "Enable installation of IL2CPP_Resolver during FetchContent builds" ON)

if(IL2CPP_RESOLVER_ENABLE_INSTALL)
    # Set installation paths for use in the config file
    set(INCLUDE_INSTALL_DIR include)
    set(LIB_INSTALL_DIR lib)
    set(CMAKE_INSTALL_DIR lib/cmake/IL2CPP_Resolver)
    
    # Ensure the install rules are executed
    include(CMakePackageConfigHelpers)
    
    # Configure and install the package config files
    configure_package_config_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/cmake/IL2CPP_ResolverConfig.cmake.in
        ${CMAKE_CURRENT_BINARY_DIR}/IL2CPP_ResolverConfig.cmake
        INSTALL_DESTINATION ${CMAKE_INSTALL_DIR}
        PATH_VARS INCLUDE_INSTALL_DIR LIB_INSTALL_DIR
    )

    # Export the targets
    install(
        EXPORT IL2CPP_ResolverTargets
        FILE IL2CPP_ResolverTargets.cmake
        NAMESPACE IL2CPP_Resolver::
        DESTINATION ${CMAKE_INSTALL_DIR}
    )
    
    # Also export with resolver namespace for backward compatibility
    install(
        EXPORT IL2CPP_ResolverTargets
        FILE resolverTargets.cmake
        NAMESPACE resolver::
        DESTINATION ${CMAKE_INSTALL_DIR}
    )
    
    # Install target and headers
    install(TARGETS IL2CPP_Resolver
        EXPORT IL2CPP_ResolverTargets
        ARCHIVE DESTINATION ${LIB_INSTALL_DIR}
        LIBRARY DESTINATION ${LIB_INSTALL_DIR}
        RUNTIME DESTINATION bin
        INCLUDES DESTINATION ${INCLUDE_INSTALL_DIR}
    )

    # Install header files from include directory with proper directory structure
    install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
        DESTINATION ${INCLUDE_INSTALL_DIR}
        FILES_MATCHING 
        PATTERN "*.h"
        PATTERN "*.hpp"
    )

    # Install the package configuration file
    install(FILES ${CMAKE_CURRENT_BINARY_DIR}/IL2CPP_ResolverConfig.cmake
        DESTINATION ${CMAKE_INSTALL_DIR}
    )

    # Export the package for use from the build tree
    export(EXPORT IL2CPP_ResolverTargets
        FILE ${CMAKE_CURRENT_BINARY_DIR}/IL2CPP_ResolverTargets.cmake
        NAMESPACE IL2CPP_Resolver::
    )
    
    # Also export with resolver namespace for backward compatibility
    export(EXPORT IL2CPP_ResolverTargets
        FILE ${CMAKE_CURRENT_BINARY_DIR}/resolverTargets.cmake
        NAMESPACE resolver::
    )
endif()