cmake_minimum_required(VERSION 3.28)
project(rhythmplayer LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)

# SFML Fetch
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.1.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

# GTest Fetch
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Enable Testing
include(CTest)
include(GoogleTest)
enable_testing()

# Main code in library
add_library(lib
    # src/parse/parser.cpp (Unused for now)
    src/parse/osuparser.cpp
    src/map/map.cpp
    src/map/osumap/osumap.cpp
    src/map/osumap/colours.cpp
    src/map/osumap/events.cpp
    src/map/osumap/sections.cpp
    src/map/osumap/timingpoints.cpp
    src/map/osumap/hitobjects.cpp
    src/map/osumap/maniawrapper.cpp
    src/game/scene.cpp
)
target_include_directories(lib PUBLIC 
    src
    src/parse
    src/map
    src/map/osumap
)

target_compile_features(lib PUBLIC cxx_std_23)

target_link_libraries(lib PUBLIC
    SFML::Graphics
)

# Main executable
add_executable(main
    src/main.cpp
)
target_link_libraries(main PRIVATE lib)

# Tests executable
add_executable(tests
    tests/test_osuwrapper.cpp
)
target_link_libraries(tests PRIVATE 
    lib
    GTest::gtest_main
)

# Add tests
gtest_discover_tests(tests)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT main)