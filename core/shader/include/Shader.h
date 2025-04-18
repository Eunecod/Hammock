#pragma once

#define USE_OPENGL // Временно указывать флаги на компиляции
#ifdef USE_OPENGL
    #include <GL/glew.h>
#endif // USE_OPENGL

#include <Common.h>


class Shader {
public:
    Shader() = default;

    const char* ReadShaderFile(const char* file_path);
    GLuint CompileShader(GLenum gl_type_shader, const char* source);
};
