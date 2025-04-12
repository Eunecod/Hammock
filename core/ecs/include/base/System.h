#pragma once

#include <utils/ECSManager.hpp>


class System {
public:
    explicit System(ECSManager& ecs) : ecs(ecs) { };
    ~System() = default;

    virtual void Update(const float) = 0;

protected:
    ECSManager& ecs;
    enum class MODE : short {
        BASE = 0,
        PHYSICS,
    } type_mode = static_cast<MODE>(0);
};
