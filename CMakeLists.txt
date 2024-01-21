cmake_minimum_required(VERSION 3.25)

##############################################
####### PROJECT wide settings
##############################################
project(strdo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out/lib)

###########################
####### Find Packages
###########################
find_package(Iconv REQUIRED)

find_package(Catch2 REQUIRED
    HINTS $ENV{HOME}/.local
    NO_DEFAULT_PATH)

##########################################################################
####### TARGET: library strdo
##########################################################################
add_library(${PROJECT_NAME} STATIC)

target_sources(${PROJECT_NAME}
    PRIVATE ${CMAKE_SOURCE_DIR}/src/strdo.cpp
    PUBLIC FILE_SET HEADERS
        BASE_DIRS ${CMAKE_SOURCE_DIR}/include
        FILES ${CMAKE_SOURCE_DIR}/include/strdo.hpp)

target_include_directories(strdo
    PRIVATE src
    PUBLIC include)

target_link_libraries(${PROJECT_NAME}
    PRIVATE Iconv::Iconv)

install(TARGETS ${PROJECT_NAME} FILE_SET HEADERS)

##########################################################################
####### TARGET: library strdo
##########################################################################
add_subdirectory(tests)
