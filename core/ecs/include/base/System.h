#pragma once


class System {
public:
    ~System() = default;

    virtual void Update(const float delta_time) = 0;
};
