//
// Created by npchitman on 6/27/21.
//

#ifndef HAZEL_ENGINE_COMPONENTS_H
#define HAZEL_ENGINE_COMPONENTS_H

#include <glm/glm.hpp>

namespace Hazel {
    struct TransformComponent {
        glm::mat4 Transform{1.0f};

        TransformComponent() = default;
        TransformComponent(const TransformComponent&) = default;
        explicit TransformComponent(const glm::mat4& transform) : Transform(transform) {}

        explicit operator glm::mat4&() { return Transform; }
        explicit operator const glm::mat4&() const { return Transform; }
    };

    struct SpriteRendererComponent {
        glm::vec4 Color{1.0f, 1.0f, 1.0f, 1.0f};

        SpriteRendererComponent() = default;
        SpriteRendererComponent(const SpriteRendererComponent&) = default;
        explicit SpriteRendererComponent(const glm::vec4& color) : Color(color) {}
    };
}// namespace Hazel


#endif//HAZEL_ENGINE_COMPONENTS_H
