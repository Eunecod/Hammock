cmake_minimum_required(VERSION 3.15)
project(Hammock)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenGL REQUIRED)
add_subdirectory(core)
add_subdirectory(lib)


add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} 
    PUBLIC glfw libglew_static glm OpenGL::GL Engine Input 
)