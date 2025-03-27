#pragma once
#include <CommonDefines.h>
#include <GameObject.h>
#include <variant>


using GameObjectTypes = std::variant<Blank>;
class Engine {
private:
    std::vector<std::unique_ptr<GameObject<GameObjectTypes>>> m_vecGameObject;

public:
    Engine();
};
