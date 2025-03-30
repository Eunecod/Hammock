#include <Engine.h>
#include <iostream>


CEngine::CEngine(Frame::Window* _window) : window(_window) { }

CEngine::~CEngine() {
    glfwTerminate();
}

void CEngine::EngineRunning() {
    Timer::TimePoint prev_time = Timer::Clock::now();

    while (!glfwWindowShouldClose(window)) {
        Timer::TimePoint current_time = Timer::Clock::now();
        Timer::Duration elapsed = current_time - prev_time;
        prev_time = current_time;

        float delta_time = elapsed.count();
        if (delta_time > MAX_DELTA_TIME) {
            delta_time = MAX_DELTA_TIME;
        }
        
        float accumulator = 0.f;
        accumulator += delta_time;
        
        while (accumulator >= PHYSICS_STEP) {
            /* Обновление физики */
            std::cout << "Update Pysics Engine " << std::endl;
            PhysicsUpdate(PHYSICS_STEP);
            accumulator -= PHYSICS_STEP;
        }

        Render();

        glfwPollEvents();
    }
}

void CEngine::AddObject(std::unique_ptr<CGameObject> object) {
    game_objects.emplace_back(std::move(object));
}

void CEngine::Update(const float delta_time) {
    for (auto& object : game_objects) {
        if (object->GetActive()) {
            object->Update(delta_time);   
        }
    }
}

void CEngine::PhysicsUpdate(const float delta_time) {
    for (auto& object : game_objects) {
        if (object->GetPhysics()) {
            object->PhysicsUpdate(delta_time);   
        }
    }
}

void CEngine::Render() {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    /* Все объекты привести к отрисовки */

    glfwSwapBuffers(window);
}