#pragma once 
#include <glm/gtc/quaternion.hpp>
#include <unordered_map>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <functional> 
#include <cstdint>
#include <string>
#include <memory>
#include <chrono>


constexpr const float TARGET_FPS        { 60.f };
constexpr const float PHYSICS_STEP      { 1.f / TARGET_FPS };
constexpr const float MAX_DELTA_TIME    { 0.25f };

namespace Engine {
    using Vector3D      = glm::vec3;
    using Scale3D       = glm::vec3;
    using Quantarion    = glm::quat;
}

namespace Frame {
    using Window = GLFWwindow;
}

namespace Timer {
    using Clock         = std::chrono::high_resolution_clock;
    using TimePoint     = std::chrono::time_point<Clock>;
    using Duration      = std::chrono::duration<float>;
}