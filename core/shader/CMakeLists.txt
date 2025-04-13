cmake_minimum_required(VERSION 3.15)
project(Shader)


add_library(${PROJECT_NAME} STATIC src/Shader.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC include)
target_link_libraries(${PROJECT_NAME} PRIVATE third_party core)