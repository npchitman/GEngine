//
// Created by npchitman on 6/28/21.
//

#ifndef HAZEL_ENGINE_SCENEHIERARCHYPANEL_H
#define HAZEL_ENGINE_SCENEHIERARCHYPANEL_H

#include "Hazel/Core/Base.h"
#include "Hazel/Core/Log.h"
#include "Hazel/Scene/Scene.h"
#include "Hazel/Scene/Entity.h"

namespace Hazel{
    class SceneHierarchyPanel {
    public:
        SceneHierarchyPanel() = default;
        explicit SceneHierarchyPanel(const Ref<Scene>& context);

        void SetContext(const Ref<Scene>& context);

        void OnImGuiRender();

    private:
        void DrawEntityNode(Entity entity);
        void DrawComponents(Entity entity);

    private:
        Ref<Scene> m_Context;
        Entity m_SelectionContext;
    };
}


#endif//HAZEL_ENGINE_SCENEHIERARCHYPANEL_H