add_subdirectory(engine)
add_subdirectory(window)
add_subdirectory(ecs)
add_subdirectory(scene)
add_subdirectory(object)


add_library(core INTERFACE)

target_link_libraries(core INTERFACE
    Window Engine ECS Object Scene
)