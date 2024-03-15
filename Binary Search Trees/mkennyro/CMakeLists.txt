cmake_minimum_required(VERSION 3.1)
project( assignment3)
# find_package(PkgConfig REQUIRED)

file(GLOB_RECURSE assignment3_src
    "src/*.cpp"
    "src/*/*.cpp"
)

add_executable(assignment3  ${assignment3_src})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ")
target_link_libraries(assignment3)
#set(EXECUTABLE_OUTPUT_PATH "../bin")
set(CMAKE_BINARY_DIR "../bin")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
