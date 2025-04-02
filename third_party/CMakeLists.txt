add_subdirectory(glfw)
add_subdirectory(glew)
add_subdirectory(glm)


add_library(third_party INTERFACE)
target_link_libraries(third_party INTERFACE
    glfw libglew_static glm
)