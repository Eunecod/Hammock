#pragma once

#define USE_OPENGL // Временно указывать флаги на компиляции
#ifdef USE_OPENGL
    #include <GLFW/glfw3.h>
#endif // USE_OPENGL

#include <Window.h>
#include <Common.h>


namespace Hammock {

    class Engine {
    public:
        Engine(Window* window);
        ~Engine();

        void Loop();
    
    private:
        Window* window { nullptr };
    };

    class Timer {
    public:
        inline float Now() const {
            return static_cast<float>(glfwGetTime());
        }
    };

} // namespace Hammock
