cmake_minimum_required(VERSION 3.1)

project(uzume_emscripten)

include(ExternalProject)

ExternalProject_add(uzume_vocoder
        PREFIX ${CMAKE_CURRENT_BINARY_DIR}/uzume_vocoder
        GIT_REPOSITORY https://github.com/haruneko/uzume_vocoder
        GIT_TAG master
        INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR}
        CMAKE_ARGS "-DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_BINARY_DIR}"
        )

file(GLOB_RECURSE VOCODER_SOURCES ./lib/uzume_vocoder/src/*.cpp)
file(GLOB_RECURSE VOCODER_HEADERS ./lib/uzume_vocoder/src/*.hpp)

include_directories(uzume_emscripten PRIVATE ./lib/uzume_vocoder/src/)

add_executable(uzume_emscripten
        src/data/ContourBindings.cpp
        src/main.cpp
        ${VOCODER_SOURCES}
        ${VOCODER_HEADERS}
        )

if (EMSCRIPTEN)
    set(CMAKE_EXECUTABLE_SUFFIX ".html")
endif()

set_target_properties(uzume_emscripten PROPERTIES LINK_FLAGS "-s DEMANGLE_SUPPORT=1 --bind")
