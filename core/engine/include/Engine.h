#pragma once

#define USE_OPENGL // Временно указывать флаги на компиляции
#ifdef USE_OPENGL
    #include <GLFW/glfw3.h>
#endif // USE_OPENGL

#include <Window.h>
#include <Scene.h>
#include <Common.h>


namespace Hammock {

    class Engine {
    public:
        Engine(Window* window, Scene* scene);
        ~Engine();

        void LoadScene(Scene* scene);
        void Loop();
    
    private:
        Window* window  { nullptr };
        Scene* scene    { nullptr };

        std::function<void(const float)> RenderPipline = [](const float alpha) { 
        };
    };

    class Timer {
    public:
        inline float Now() const {
            return static_cast<float>(glfwGetTime());
        }
    };

} // namespace Hammock
