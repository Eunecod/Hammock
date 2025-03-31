#pragma once

#define USE_OPENGL // Временно указывать флаги на компиляции
#ifdef USE_OPENGL
    #include <GLFW/glfw3.h>
#endif // USE_OPENGL

#define USE_LOGGER // Временно указывать флаги на компиляции
#ifdef USE_LOGGER
    #include <iostream>
#endif // USE_LOGGER


namespace Hammock {

    class Window {
    public:
        Window(int width, int height, const char* title);
        ~Window();

        void CreateInstance();
        void Ratio();
        int Run();

        inline GLFWwindow* GetWindowHandle() const {
            return window;
        }
        
        inline int GetWidth() const { 
            return width;
        }

        inline int GetHeight() const { 
            return height;
        }

        class Frame {
        public:
            Frame(GLFWwindow* window) : window(window) {
                glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                    
                glEnable(GL_DEPTH_TEST);
            } 

            ~Frame() {
                glfwSwapBuffers(window);
                glfwPollEvents();
            }
        private:
            GLFWwindow* window;
        };

    protected:
        bool Close(GLFWwindow* window);
        void Free();

    private:
        GLFWwindow* window  { nullptr };
        int width   { 0 };
        int height  { 0 };
        const char* title { "" };
    };

} // namespace Hammock
