cmake_minimum_required(VERSION 3.15)
project(Hammock)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenGL REQUIRED)
add_subdirectory(core/glfw)
add_subdirectory(core/glew)
add_subdirectory(core/glm)


add_executable(${PROJECT_NAME} source/main.cpp)

target_link_libraries(${PROJECT_NAME} glfw libglew_static glm OpenGL::GL)
