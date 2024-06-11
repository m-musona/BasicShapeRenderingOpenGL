#include "Shader.h"

#include <glad/glad.h>
#include <iostream>

Shader::Shader(const char* vertexShaderSource, const char* fragmentShaderSource)
{
    mVertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(mVertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(mVertexShader);

    mFragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(mFragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(mFragmentShader);
}
Shader::~Shader()
{
    DeleteProgram();
}

void Shader::Compile()
{
    // check for shader compile errors
    int success;
    char infoLog[512];
    glGetShaderiv(mVertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(mVertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    // check for shader compile errors
    glGetShaderiv(mFragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(mFragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
}

void Shader::Link()
{
    int success;
    char infoLog[512];

    // link shaders
    mShaderProgram = glCreateProgram();
    glAttachShader(mShaderProgram, mVertexShader);
    glAttachShader(mShaderProgram, mFragmentShader);
    glLinkProgram(mShaderProgram);
    // check for linking errors
    glGetProgramiv(mShaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(mShaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
    glDeleteShader(mVertexShader);
    glDeleteShader(mFragmentShader);
}

void Shader::UseProgram()
{
    glUseProgram(mShaderProgram);
}

void Shader::DeleteProgram()
{
    glDeleteProgram(mShaderProgram);
}

void Shader::SetUniformFloat4(std::string name, glm::vec4 value)
{
    int location = glGetUniformLocation(mShaderProgram, name.c_str());
    glUniform4f(location, value.x, value.y, value.z, value.w);
}

void Shader::SetUniformFloat3(std::string name, glm::vec3 value)
{
    int location = glGetUniformLocation(mShaderProgram, name.c_str());
    glUniform3f(location, value.x, value.y, value.z);
}

void Shader::SetUniformFloat(std::string name, float value)
{
    int location = glGetUniformLocation(mShaderProgram, name.c_str());
    glUniform1f(location, value);
}

void Shader::SetUniformInt(std::string name, int value)
{
    int location = glGetUniformLocation(mShaderProgram, name.c_str());
    glUniform1i(location, value);
}
