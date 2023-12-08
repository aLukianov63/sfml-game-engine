cmake_minimum_required(VERSION 3.15)
project(GameTest
        LANGUAGES CXX
        VERSION 23
)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(dependencies)
add_subdirectory(src)
add_subdirectory(resources)
