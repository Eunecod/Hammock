#pragma once

#include <ECS.h>
#include <Common.h>


class Scene { 
public:
    Scene() = default;
    
    template <typename T, typename... Args>
    inline T CreateGameObject(Args&&... args) {
        auto object = std::make_unique<T>(ecs, std::forward<Args>(args)...);
        nodes.push_back(object->GetIndex());

        return *object;
    }

    template<typename T, typename... Args>
    inline void RegisterSystem(Args&&... args) {
        auto system = std::make_unique<T>(ecs, std::forward<Args>(args)...);
        
        if (system.type_mode == System::MODE::BASE) {
            systems.emplace_back(std::move(system));
        }

        if (system.type_mode == System::MODE::PHYSICS) {
            physics_systems.emplace_back(std::move(system));
        }
    }

    void UpdatePhysics(const float delta_physics_time);
    void Update(const float delta_time);
    void Render(const float alpha, std::function<void(const float)>& callback_render_pipline);

private:
    ECSManager ecs;
    std::vector<Entity> nodes;
    std::vector<std::unique_ptr<System>> systems;
    std::vector<std::unique_ptr<System>> physics_systems;
};