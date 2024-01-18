cmake_minimum_required(VERSION 3.24)

# PROJECT
project(
    strdo
    LANGUAGES CXX
)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# OUTPUT
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out/${CMAKE_BUILD_TYPE})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out/${CMAKE_BUILD_TYPE}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out/${CMAKE_BUILD_TYPE}/lib)

# INSTALL
if(NOT CMAKE_INSTALL_PREFIX)
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/install)
    else()
        set(CMAKE_INSTALL_PREFIX $ENV{HOME}/.local)
    endif()
endif()

include(cmake/iconv-config.cmake)

# library strdo 
add_library(${PROJECT_NAME} STATIC)
target_sources(${PROJECT_NAME}
    PRIVATE ${CMAKE_SOURCE_DIR}/src/strdo.cpp
    PUBLIC ${CMAKE_SOURCE_DIR}/include/strdo.hpp)
target_include_directories(strdo
    PRIVATE src
    PUBLIC include)
target_link_libraries(${PROJECT_NAME}
    PRIVATE iconv)
set_target_properties(${PROJECT_NAME} PROPERTIES
    PUBLIC_HEADER include/strdo.hpp)
install(TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION lib
    PUBLIC_HEADER DESTINATION include)


# Tests
find_package(Catch2 REQUIRED)
add_subdirectory(tests)
