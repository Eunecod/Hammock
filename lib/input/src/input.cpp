#include <input.h>
#include <iostream>


void Input::KeyPress(GLFWwindow* pWindow, int nKey, int nScancode, int nAction, int nMods) {
    if (nKey == GLFW_KEY_ESCAPE && nAction == GLFW_PRESS) {
        std::cout << "Check Press" << std::endl;
        glfwSetWindowShouldClose(pWindow, true);
    }
}