#pragma once
#include <CommonDefines.h>
#include <GameObject.h>


class CEngine {
private:
    Frame::Window* window { nullptr };
    std::vector<std::unique_ptr<CGameObject>> game_objects;
    
public:
    CEngine(Frame::Window* _window);
    ~CEngine();

    static void InputCallback(Frame::Window* window, int key, int scancode, int action, int mods);

    void EngineRunning();
    void AddObject(std::unique_ptr<CGameObject> object);
    
protected:
    void Update(const float delta_time);
    void PhysicsUpdate(const float delta_time);
    void Render(const float alpha);
    void Input();
};
