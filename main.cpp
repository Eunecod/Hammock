#include <Window.h>
#include <Scene.h>
#include <Engine.h>


int main() {
    Hammock::Window window(800, 600, "Hammock");
    window.CreateInstance();

    Scene scene;

    Hammock::Engine engine(&window, &scene);
    engine.Loop();

    return 0;
}