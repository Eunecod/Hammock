cmake_minimum_required(VERSION 3.15)
project(Hammock)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenGL REQUIRED)
add_subdirectory(third_party)
add_subdirectory(core)


add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} 
    PUBLIC OpenGL::GL third_party core
)