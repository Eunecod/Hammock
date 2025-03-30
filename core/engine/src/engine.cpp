#include <Engine.h>
#include <iostream>


CEngine::CEngine(Frame::Window* _window) : window(_window) { }

CEngine::~CEngine() {
    glfwTerminate();
}

void CEngine::EngineRunning() {
    glfwSwapInterval(1);

    Timer::TimePoint prev_time = Timer::Clock::now();
    float accumulator = 0.f;

    while (!glfwWindowShouldClose(window)) {
        Timer::TimePoint current_time = Timer::Clock::now();
        Timer::Duration elapsed = current_time - prev_time;
        prev_time = current_time;

        float delta_time = std::min(elapsed.count(), MAX_DELTA_TIME);
        
        accumulator += delta_time;
        while (accumulator >= MIN_PHYSICS_STEP) {
            float delta_physics_time = std::min(accumulator, TARGET_PHYSICS_STEP);
            PhysicsUpdateHandler(delta_physics_time);
            accumulator -= delta_physics_time;
        }

        UpdateHandler(delta_time);

        const float alpha = accumulator / MIN_PHYSICS_STEP;
        RenderHandler(alpha);

        InputHandler();
    }
}

void CEngine::AddObject(std::unique_ptr<CGameObject> object) {
    game_objects.emplace_back(std::move(object));
}

void CEngine::UpdateHandler(const float delta_time) {
    for (auto& object : game_objects) {
        object->Update(delta_time);   
    }

    glfwPollEvents();
}

void CEngine::PhysicsUpdateHandler(const float delta_time) {
    for (auto& object : game_objects) {
        object->PhysicsUpdate(delta_time);   
    }
}

void CEngine::RenderHandler(const float alpha) {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    float aspect = (float)800 / (float)600;
    glFrustum(-0.5f, 0.5f, -0.5f/aspect, 0.5f/aspect, 1.0f, 100.0f);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    for(const auto& object : game_objects) {
        glTranslatef(object->GetTransform().position.x, object->GetTransform().position.y, object->GetTransform().position.z);
        glColor3f(1.0f, 0.5f, 0.0f);
        
        glBegin(GL_QUADS);
            glVertex3f(-1.0f, -1.0f,  1.0f);
            glVertex3f( 1.0f, -1.0f,  1.0f);
            glVertex3f( 1.0f,  1.0f,  1.0f);
            glVertex3f(-1.0f,  1.0f,  1.0f);

            glVertex3f(-1.0f, -1.0f, -1.0f);
            glVertex3f(-1.0f,  1.0f, -1.0f);
            glVertex3f( 1.0f,  1.0f, -1.0f);
            glVertex3f( 1.0f, -1.0f, -1.0f);

            glVertex3f(-1.0f,  1.0f, -1.0f);
            glVertex3f(-1.0f,  1.0f,  1.0f);
            glVertex3f( 1.0f,  1.0f,  1.0f);
            glVertex3f( 1.0f,  1.0f, -1.0f);

            glVertex3f(-1.0f, -1.0f, -1.0f);
            glVertex3f( 1.0f, -1.0f, -1.0f);
            glVertex3f( 1.0f, -1.0f,  1.0f);
            glVertex3f(-1.0f, -1.0f,  1.0f);

            glVertex3f( 1.0f, -1.0f, -1.0f);
            glVertex3f( 1.0f,  1.0f, -1.0f);
            glVertex3f( 1.0f,  1.0f,  1.0f);
            glVertex3f( 1.0f, -1.0f,  1.0f);

            glVertex3f(-1.0f, -1.0f, -1.0f);
            glVertex3f(-1.0f, -1.0f,  1.0f);
            glVertex3f(-1.0f,  1.0f,  1.0f);
            glVertex3f(-1.0f,  1.0f, -1.0f);
        glEnd();
    }

    glDisable(GL_DEPTH_TEST);
    glfwSwapBuffers(window);
}

void CEngine::InputCallback(Frame::Window* window, int key, int scancode, int action, int mods) {

}

void CEngine::InputHandler() {

}