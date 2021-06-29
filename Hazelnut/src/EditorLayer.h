//
// Created by npchitman on 6/24/21.
//

#ifndef HAZEL_ENGINE_EDITORLAYER_H
#define HAZEL_ENGINE_EDITORLAYER_H

#include "Hazel.h"
#include "Hazel/Renderer/EditorCamera.h"
#include "Panels/SceneHierarchyPanel.h"

namespace Hazel {

    class EditorLayer : public Layer {
    public:
        EditorLayer();
        ~EditorLayer() override = default;

        void OnAttach() override;
        void OnDetach() override;

        void OnUpdate(Timestep ts) override;
        void OnImGuiRender() override;
        void OnEvent(Event& e) override;

    private:
        bool OnKeyPressed(KeyPressedEvent& e);
        void NewScene();
        void OpenScene();
        void SaveSceneAs();

    private:
        Hazel::OrthographicCameraController m_CameraController;

        // Temp
        Ref<VertexArray> m_SquareVA;
        Ref<Shader> m_FlatColorShader;
        Ref<Framebuffer> m_Framebuffer;

        Ref<Scene> m_ActiveScene;
        Entity m_SquareEntity;
        Entity m_CameraEntity;
        Entity m_SecondCamera;

        Entity m_HoveredEntity;

        bool m_PrimaryCamera = true;

        EditorCamera m_EditorCamera;

        Ref<Texture2D> m_CheckerboardTexture;

        bool m_ViewportFocused = false, m_ViewportHovered = false;
        glm::vec2 m_ViewportSize = {0.0f, 0.0f};
        glm::vec2 m_ViewportBounds[2]{};

        glm::vec4 m_SquareColor = {0.2f, 0.3f, 0.8f, 1.0f};

        int m_GizmoType = -1;

        SceneHierarchyPanel m_SceneHierarchyPanel;
    };

}// namespace Hazel

#endif//HAZEL_ENGINE_EDITORLAYER_H
