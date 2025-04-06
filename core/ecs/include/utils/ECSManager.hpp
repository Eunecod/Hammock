#pragma once

#include <Common.h>
#include <base/Component.h>
#include <base/Entity.h>
#include <base/System.h>



struct SparseSet {
    static constexpr Entity INVALID_ENTITY = std::numeric_limits<Entity>::max();

    virtual ~SparseSet() = default;
    virtual void remove(Entity entity) = 0;
};

template<typename T>
struct ComponentSparseSet : public SparseSet {
    std::vector<T>          components; // dense
    std::vector<Entity>     entities;   // sparse
    std::vector<size_t>     indices;

    void add(Entity entity, T&& component) {
        if (entity >= entities.size()) {
            entities.resize(entity + 1, INVALID_ENTITY);
        }
        
        if (entities[entity] != INVALID_ENTITY) {
            return;
        }
        
        entities[entity] = components.size();
        indices.push_back(entity);
        components.emplace_back(std::move(component));
    }

    void remove(Entity entity) override {
        if (entity >= entities.size() || entities[entity] == INVALID_ENTITY) {
            return;
        }
        
        size_t index = entities[entity];
        Entity last_entity = indices.back();
        
        if (index != components.size() - 1) {
            components[index] = std::move(components.back());
            indices[index] = last_entity;
            entities[last_entity] = index;
        }
        
        components.pop_back();
        indices.pop_back();
        entities[entity] = INVALID_ENTITY;
    }

    T* get(Entity entity) {
        return contains(entity) ? &components[entities[entity]] : nullptr;
    }

    bool contains(Entity entity) const {
        return entity < entities.size() && entities[entity] != INVALID_ENTITY;
    }

    auto begin() const { 
        return components.begin(); 
    }

    auto end() const { 
        return components.end();
    }
};

class ECSManager {
public:
    inline Entity CreateEntity() {
        return next_index++;
    }

    template<typename T, typename... Args>
    T& AddComponent(Entity entity, Args&&... args) {
        auto type = std::type_index(typeid(T));
        
        if (component_storage.find(type) == component_storage.end()) {
            component_storage[type] = std::make_unique<ComponentSparseSet<T>>();
        }
        
        auto sparse_set = static_cast<ComponentSparseSet<T>*>(component_storage[type].get());
        sparse_set->add(entity, T{std::forward<Args>(args)...});
        return *sparse_set->get(entity);
    }

    template<typename T>
    T* GetComponent(Entity entity) {
        auto type = std::type_index(typeid(T));
        if (component_storage.find(type) != component_storage.end()) {
            auto sparse_set = static_cast<ComponentSparseSet<T>*>(component_storage[type].get());
            return sparse_set->get(entity);
        }

        return nullptr;
    }

    template<typename T>
    ComponentSparseSet<T>* GetSparseSet() const {
        auto type = std::type_index(typeid(T));
        auto it = component_storage.find(type);
        if (it != component_storage.end()) {
            return static_cast<ComponentSparseSet<T>*>(it->second.get());
        }

        return nullptr;
    }

    template<typename T>
    void RemoveComponent(Entity entity) {
        auto type = std::type_index(typeid(T));
        if (component_storage.find(type) != component_storage.end()) {
            component_storage[type]->remove(entity);
        }
    }

private:
    Entity next_index = 1;
    std::unordered_map<std::type_index, std::unique_ptr<SparseSet>> component_storage;
};
