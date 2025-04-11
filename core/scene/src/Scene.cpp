#include <Scene.h>


void Scene::UpdatePhysics(const float delta_physics_time) {
    for (auto& physics_system : physics_systems) {
        physics_system->Update(delta_physics_time);
    }
}

void Scene::Update(const float delta_time) {
    for (auto& system : systems) {
        system->Update(delta_time);
    }
}
