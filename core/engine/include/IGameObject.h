#pragma once
#include <CommonDefines.h>


class IGameObject {
public:
    ~IGameObject() = default;

    virtual void Update(const float delta_time) = 0;
    virtual void PhysicsUpdate(const float delta_time) = 0;
};
