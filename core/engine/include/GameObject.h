#pragma once
#include <IGameObject.h>


#define OBJECT_PROPERTY(TYPE, NAME, DEFAULT_VALUE) \
        private: \
            TProperty<TYPE> _##NAME##_prop{DEFAULT_VALUE}; \
        public: \
            const TYPE& Get##NAME() const { return _##NAME##_prop.Get(); } \
            void Set##NAME(const TYPE& value) { _##NAME##_prop.Set(value); } \

template <typename T> class TProperty {
private:
    T property;
public:
    explicit TProperty(const T& value = T { }) : property(value) { }
    const T& Get() const { return property; }
    void Set(const T& value) { property = value; }
};

struct Transform {
    Engine::Vector3D    position;
    Engine::Quaternion  rotation;
    Engine::Scale3D     scale;

    Transform() : position(0.f, 0.f, 0.f), rotation(1.f, 0.f, 0.f, 0.f), scale(1.f, 1.f, 1.f) { }
};

class CGameObject : public IGameObject {
    OBJECT_PROPERTY(Transform, Transform, {});

public:
    CGameObject() = default;
};
