#include <Shader.h>
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

    Shader vertex_shader;
    GLuint vertex = vertex_shader.CompileShader(GL_VERTEX_SHADER, vertex_shader.ReadShaderFile("vertex.glsl"));

    Shader fragment_shader;
    GLuint fragment = fragment_shader.CompileShader(GL_FRAGMENT_SHADER, fragment_shader.ReadShaderFile("fragment.glsl"));

    GLuint shader_program = glCreateProgram();
    glAttachShader(shader_program, vertex);
    glAttachShader(shader_program, fragment);
    glLinkProgram(shader_program);

    glDeleteShader(vertex);
    glDeleteShader(fragment);

    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };

    GLuint VAO, VBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    RenderPipline = [&shader_program, &VAO](const float alpha) {
        glUseProgram(shader_program);
        glBindVertexArray(VAO);

        glDrawArrays(GL_TRIANGLES, 0, 3);
    };

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
