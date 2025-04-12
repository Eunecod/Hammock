#include <Engine.h>


Hammock::Engine::Engine(Hammock::Window* window, Scene* scene) : window(window), scene(scene) { }

Hammock::Engine::~Engine() { }

void Hammock::Engine::LoadScene(Scene* scene) {
    if (!scene) { return; }

    this->scene = scene;
}

void Hammock::Engine::Loop() {
    Hammock::Timer timer;

    float prev_time = timer.Now();
    float accumulator = 0.f;

    while (window->Run()) {
        Hammock::Window::Frame frame(window->GetWindowHandle());
        window->Ratio();

        float current_time = timer.Now();
        float delta_time = current_time - prev_time;
        prev_time = current_time;

        delta_time = std::min(delta_time, MAX_DELTA_TIME);

        // Обработка ввода
        
        accumulator += delta_time;
        while (accumulator >= MIN_PHYSICS_STEP) {
            const float delta_physics_time = std::min(accumulator, TARGET_PHYSICS_STEP);
            // Обновление физики // delta_physics_time
            if (scene) {
                scene->UpdatePhysics(delta_physics_time);
            }

            accumulator -= delta_physics_time;
        }

        // Обновление логики // delta_time
        if (scene) {
            scene->Update(delta_time);
        }

        const float alpha = accumulator / MIN_PHYSICS_STEP;
        // Обновление рендера // alpha
        if (scene) {
            scene->Render(alpha, RenderPipline);
        }
    }
}
