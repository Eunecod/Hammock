cmake_minimum_required(VERSION 3.15)
project(ecs)

set(SOURCE 
    src/ECSManager.cpp
)

add_library(${PROJECT_NAME} STATIC ${SOURCE})

target_include_directories(${PROJECT_NAME} PUBLIC include)
target_link_libraries(${PROJECT_NAME} PRIVATE third_party core)