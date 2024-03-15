cmake_minimum_required(VERSION 3.5.0)
project(mkennyro)

file(GLOB_RECURSE mkennyro
"src/*.cpp"
"src/*/*.cpp"
)
add_executable(mkennyro ${mkennyro})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ")
target_link_libraries(mkennyro)
#set(EXECUTABLE_OUTPUT_PATH "../bin")
set(CMAKE_BINARY_DIR "../bin")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
