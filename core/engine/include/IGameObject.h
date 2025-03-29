#pragma once
#include <CommonDefines.h>


class IGameObject {
public:
    ~IGameObject() = default;

    virtual void Update(double delta_time) = 0;
    virtual void PhysicsUpdate(double delta_time) = 0;
};
