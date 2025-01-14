cmake_minimum_required(VERSION 3.28)
project(notebook)

set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 14)

file(GLOB SOURCES "*.c" "*.cpp")

foreach(SOURCE ${SOURCES})
    get_filename_component(BASENAME ${SOURCE} NAME_WLE)
    get_filename_component(EXTENSION ${SOURCE} LAST_EXT)
    if(EXTENSION STREQUAL ".c")
        add_executable(${BASENAME}_c ${SOURCE})
    elseif(EXTENSION STREQUAL ".cpp")
        add_executable(${BASENAME}_cpp ${SOURCE})
    endif()
endforeach()
