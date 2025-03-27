#pragma once
#include <CommonDefines.h>


template <typename Derived> class GameObject {
private:
    glm::vec3 m_Position;
    glm::quat m_Rotation;

    GameObject* m_pParent { nullptr };
    std::vector<GameObject*> m_pChildren;

public:
    GameObject(void) { }

    GameObject* GetParent(void) const {
        return m_pParent;
    }

    const std::vector<GameObject*>& GetChildren(void) const {
        return m_pChildren;
    }

    void UpdateObject(double dDelta = 0.0) {
        static_cast<Derived*>(this)->Update(dDelta);
    }
};

class Blank : public GameObject<Blank> {
public:
    void Update(float deltaTime) { }
};
