#pragma once 
#include <unordered_map>
#include <functional> 
#include <cstdint>
#include <string>
#include <memory>
#include <chrono>

/* OpenGL */
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


constexpr const float MIN_FPS           { 30.f };
constexpr const float TARGET_FPS        { 60.f };
constexpr const float MAX_FPS           { 140.f };

constexpr float MIN_PHYSICS_STEP        { 1.f / MAX_FPS };    
constexpr float TARGET_PHYSICS_STEP     { 1.f / TARGET_FPS }; 
constexpr float MAX_PHYSICS_STEP        { 1.f / MIN_FPS };

constexpr const float MAX_DELTA_TIME    { 0.05f };

namespace Engine {
    using Vector3D      = glm::vec3;
    using Scale3D       = glm::vec3;
    using Quaternion    = glm::quat;
}

namespace Event {
    using Input = int;
}

namespace Frame {
    using Window = GLFWwindow;
}

namespace Timer {
    using Clock         = std::chrono::high_resolution_clock;
    using TimePoint     = std::chrono::time_point<Clock>;
    using Duration      = std::chrono::duration<float>;
}