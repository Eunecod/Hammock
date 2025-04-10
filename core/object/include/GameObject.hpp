#pragma once

#include <ECS.h>

#define SETUP void Setup()


template<typename Object>
class GameObject {
public:
    inline GameObject(ECSManager& ecs) : ecs(ecs), index(ecs.CreateEntity()) {
        static_cast<Object*>(this)->Setup();
    }

    virtual ~GameObject() { }

    template<typename T, typename... Args>
    T& AddComponent(Args&&... args) {
        return ecs.template AddComponent<T>(index, std::forward<Args>(args)...);
    }

    inline Entity GetIndex() const {
        return index;
    }

private:
    Entity index;
    ECSManager& ecs;
};
