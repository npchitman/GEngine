//
// Created by npchitman on 6/1/21.
//

#ifndef HAZEL_ENGINE_RENDERERAPI_H
#define HAZEL_ENGINE_RENDERERAPI_H

#include <glm/glm.hpp>

#include "Hazel/Renderer/VertexArray.h"

namespace Hazel {
    class RendererAPI {
    public:
        enum class API { None = 0,
                         OpenGL = 1 };

    public:
        virtual void Init() = 0;
        virtual void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) = 0;
        virtual void SetClearColor(const glm::vec4 &color) = 0;
        virtual void Clear() = 0;
        virtual void DrawIndexed(const std::shared_ptr<VertexArray> &vertexArray) = 0;
        inline static API GetAPI() { return s_API; }

        static Scope<RendererAPI> Create();
    private:
        static API s_API;
    };
}// namespace Hazel

#endif// HAZEL_ENGINE_RENDERERAPI_H
