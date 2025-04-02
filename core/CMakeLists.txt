add_subdirectory(engine)
add_subdirectory(window)


add_library(core INTERFACE)
target_link_libraries(core INTERFACE
    Window Engine 
)