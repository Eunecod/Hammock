#include <Window.h>


Hammock::Window::Window(int width, int height, const char* title) 
    : width(width), height(height), title(title) {
    if (!glfwInit()) { 
    #ifdef USE_LOGGER
        std::cerr << "[ERROR] Failed to initialize." << std::endl;
    #endif // USE_LOGGER
        Free();
    }
}

Hammock::Window::~Window() {
    Free();
}

void Hammock::Window::CreateInstance() {
    window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (!window) {
    #ifdef USE_LOGGER
        std::cerr << "[ERROR] Failed to initialize window." << std::endl;
    #endif // USE_LOGGER
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
}

bool Hammock::Window::Close(GLFWwindow* window) {
    if(glfwWindowShouldClose(window)) {
        return false;
    }

    return true;
}

int Hammock::Window::Run() {
    return Close(window);
}

void Hammock::Window::Ratio() {
    glfwGetFramebufferSize(window, &width, &height);

    /* Проверка на height == 0 */
    height = height ? height : 1;
    float aspect = static_cast<float>(width) / static_cast<float>(height);
    
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-0.5f * aspect, 0.5f * aspect, -0.5f, 0.5f, 1.0f, 100.0f);
}

void Hammock::Window::Free() {
    glfwTerminate();
    glfwDestroyWindow(window);
}
