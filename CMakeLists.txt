cmake_minimum_required(VERSION 3.1)

project(uzume_emscripten)

include(ExternalProject)

file(GLOB_RECURSE VOCODER_SOURCES ./lib/uzume_vocoder/src/*.cpp)
file(GLOB_RECURSE VOCODER_HEADERS ./lib/uzume_vocoder/src/*.hpp)

include_directories(uzume_emscripten PRIVATE ./lib/uzume_vocoder/src/)

add_executable(uzume_emscripten
        src/EstimateF0Bindings.cpp
        src/SpectrogramBindings.cpp
        src/SynthesizeWaveformBindings.cpp
        src/data/ContourBindings.cpp
        src/data/WaveformBindings.cpp
        src/spectrogram/WaveformSpectrogramBindings.cpp
        src/world/EstimateF0WithDIOBindings.cpp
        ${VOCODER_SOURCES}
        ${VOCODER_HEADERS}
        )

if (EMSCRIPTEN)
    set(CMAKE_EXECUTABLE_SUFFIX ".html")
endif()

set_target_properties(uzume_emscripten PROPERTIES LINK_FLAGS "-s DEMANGLE_SUPPORT=1 --bind")
