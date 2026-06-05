cmake_minimum_required(VERSION 3.28)
project(rhythmplayer LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.1.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(main
    src/main.cpp
    src/parse/parser.cpp
    src/parse/osuparser.cpp
    src/map/map.cpp
    src/map/osumap/osumap.cpp
    src/map/osumap/colours.cpp
    src/map/osumap/events.cpp
    src/map/osumap/sections.cpp
    src/map/osumap/timingpoints.cpp
    src/map/osumap/hitobjects.cpp
)
target_include_directories(main PRIVATE 
    src
    src/parse
    src/map
    src/map/osumap
)
target_compile_features(main PRIVATE cxx_std_17)
target_link_libraries(main PRIVATE SFML::Graphics)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT main)