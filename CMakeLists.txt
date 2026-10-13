
cmake_minimum_required(VERSION 3.20)

project(MiniRedis LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(miniredis
    src/main.cpp
    src/database.cpp
)

target_include_directories(miniredis PRIVATE include)

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
    target_compile_options(miniredis PRIVATE
        -Wall -Wextra -Wpedantic
    )
endif()

enable_testing()

add_executable(database_test
    tests/database_test.cpp
    src/database.cpp
)

target_include_directories(database_test PRIVATE include)

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
    target_compile_options(database_test PRIVATE
        -Wall -Wextra -Wpedantic
    )
endif()

add_test(
    NAME DatabaseTests
    COMMAND database_test
)
