#include <Engine.h>
#include <Window.h>


int main() {
    Hammock::Window window(800, 600, "Hammock");
    window.CreateInstance();

    Hammock::Engine engine(&window);
    engine.Loop();

    return 0;
}