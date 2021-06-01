//
// Created by npchitman on 6/1/21.
//

#include "hzpch.h"
#include "Shader.h"

#include <glad/glad.h>

Hazel::Shader::Shader(const std::string &vertexSrc, const std::string &fragmentSrc) {
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    const GLchar *source = vertexSrc.c_str();
    glShaderSource(vertexShader, 1, &source, nullptr);

    glCompileShader(vertexShader);

    GLint isCompiled = 0;
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &isCompiled);
    if (isCompiled == GL_FALSE) {
        GLint maxLength = 0;

        std::vector<GLchar> infoLog(maxLength);
        glGetShaderInfoLog(vertexShader, maxLength, &maxLength, &infoLog[0]);

        // We don't need the shader anymore.
        glDeleteShader(vertexShader);

        HZ_CORE_ERROR("{0}", infoLog.data());
        HZ_CORE_ASSERT(false, "Vertex shader compilation failure!");
        return;
    }

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    source = fragmentSrc.c_str();
    glShaderSource(fragmentShader, 1, &source, nullptr);

    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &isCompiled);
    if (isCompiled == GL_FALSE) {
        GLint maxLength = 0;

        std::vector<GLchar> infoLog(maxLength);
        glGetShaderInfoLog(fragmentShader, maxLength, &maxLength, &infoLog[0]);

        // We don't need the shader anymore.
        glDeleteShader(fragmentShader);

        HZ_CORE_ERROR("{0}", infoLog.data());
        HZ_CORE_ASSERT(false, "Fragment shader compilation failure!");
        return;
    }

    m_RendererID = glCreateProgram();
    GLuint program = m_RendererID;

    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);

    glLinkProgram(program);

    GLint isLinked = 0;
    glGetProgramiv(program, GL_LINK_STATUS, (int*)&isLinked);
    if (isLinked == GL_FALSE)
    {
        GLint maxLength = 0;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);

        // The maxLength includes the NULL character
        std::vector<GLchar> infoLog(maxLength);
        glGetProgramInfoLog(program, maxLength, &maxLength, &infoLog[0]);

        // We don't need the program anymore.
        glDeleteProgram(program);
        // Don't leak shaders either.
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);

        HZ_CORE_ERROR("{0}", infoLog.data());
        HZ_CORE_ASSERT(false, "Shader link failure!");
        return;
    }

    glDetachShader(program, vertexShader);
    glDetachShader(program, fragmentShader);
}

Hazel::Shader::~Shader() {
    glDeleteProgram(m_RendererID);
}

void Hazel::Shader::Bind() const {
    glUseProgram(m_RendererID);
}

void Hazel::Shader::UnBind() const {
    glUseProgram(0);
}