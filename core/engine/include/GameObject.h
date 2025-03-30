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

class CGameObject : public IGameObject {
    OBJECT_PROPERTY(Engine::Vector3D, Position, Engine::Vector3D(0.f, 0.f, 0.f));
    OBJECT_PROPERTY(Engine::Vector3D, Scale, Engine::Vector3D(0.f, 0.f, 0.f));
    OBJECT_PROPERTY(Engine::Quantarion, Rotation, Engine::Quantarion(1.f, 0.f, 0.f, 0.f));
    OBJECT_PROPERTY(bool, Active, true);
    OBJECT_PROPERTY(bool, Physics, true);

public:
    CGameObject() = default;
};
