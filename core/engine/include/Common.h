#pragma once 

// stdc++ includes
#include <stdint.h>

// GLM includes
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

constexpr float MIN_FPS                 = 30.0f;
constexpr float TARGET_FPS              = 60.0f;
constexpr float MAX_FPS                 = 140.f;

constexpr float MIN_PHYSICS_STEP        = 1.f / MAX_FPS;    
constexpr float TARGET_PHYSICS_STEP     = 1.f / TARGET_FPS; 
constexpr float MAX_PHYSICS_STEP        = 1.f / MIN_FPS;

constexpr float MAX_DELTA_TIME          = 0.05f;


namespace Type {

    using Vector3D      = glm::vec3;
    using Quaternion    = glm::quat;

} // namespace Type
