#pragma once
#include <CommonDefines.h>


template <typename Derived> class GameObject {
private:
    glm::vec3 m_Position;
    glm::quat m_Rotation;

    std::unique_ptr<Derived> m_pParent;
    std::vector<std::unique_ptr<Derived>> m_pChildren;

public:
    GameObject(void) { }
    ~GameObject(void) = default;

    void AddComponent(std::unique_ptr<Derived> pChildren) {
        if (!pChildren->GetParent()) {
            pChildren->SetParent(static_cast<Derived*>(this));
            m_pChildren.push_back(std::move(pChildren));
        }
    }

    void SetParent(std::unique_ptr<Derived> pParent) {
        m_pParent = std::move(pParent);
    }

    GameObject* GetParent(void) const {
        return m_pParent;
    }

    std::vector<Derived*> GetChildren() const {
        std::vector<Derived*> children;
        for (const auto& child : m_pChildren)
            children.push_back(child.get());
        return children;
    }

    void UpdateObject(double dDelta = 0.0) {
        static_cast<Derived*>(this)->Update(dDelta);
    }
};

class Blank : public GameObject<Blank> {
public:
    void Update(double deltaTime) { }
};
