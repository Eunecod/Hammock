#include <Shader.h>
#include <stdio.h>


const char* Shader::ReadShaderFile(const char* file_path) {
    FILE* file = fopen(file_path, "rb");
    if (!file) {
        return nullptr;
    }

    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* buffer = new char[length + 1];
    size_t bytesRead = fread(buffer, 1, length, file);
    buffer[bytesRead] = '\0';

    fclose(file);

    return buffer;
}

GLuint Shader::CompileShader(int gl_type_shader, const char* source) {
    if (!source) {
        return 0;
    }

    GLuint shader = glCreateShader(gl_type_shader);
    glShaderSource(shader, 1, &source, nullptr);
    glCompileShader(shader);

    GLint success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        GLchar infoLog[512];
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        glDeleteShader(shader);

        return 0;
    }

    return shader;
}