cmake_minimum_required(VERSION 3.16)

project(dyarrayd
        VERSION 0.1.0
        DESCRIPTION "A library for dynamic array in C"
        LANGUAGES C)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    set(CMAKE_C_STANDARD C11)

    set_property(GLOBAL PROPERTY USE_FOLDERS ON)

    include(CTest)
endif()

add_subdirectory(src)

if((CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME OR DYARRAYD_BUILD_TESTING))
    add_subdirectory(tests)
endif()
