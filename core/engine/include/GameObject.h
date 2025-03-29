#pragma once
#include <IGameObject.h>


#define OBJECT_PROPERTY(TYPE, NAME, PROPS) \
        private: \
            TYPE PROPS; \
        public: \
            const TYPE& Get##NAME() const { return PROPS; } \
            void Set##NAME(const TYPE& value) { PROPS = value; } \

class CGameObject : public IGameObject {
    OBJECT_PROPERTY(Engine::Vector3D, Position, position);
    OBJECT_PROPERTY(Engine::Scale3D, Scale, scale);
    OBJECT_PROPERTY(Engine::Quantarion, Rotation, rotation);
    OBJECT_PROPERTY(bool, Active, is_active);
    OBJECT_PROPERTY(bool, Physics, is_physics);

public:
    CGameObject() = default;
};
