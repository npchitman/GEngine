//
// Created by Npchitman on 2021/1/20.
//

#ifndef HAZELENGINE_WINDOWSWINDOW_H
#define HAZELENGINE_WINDOWSWINDOW_H

#include "hzpch.h"
#include "Hazel/Window.h"
#include "Hazel/Log.h"

namespace Hazel{
    class WindowsWindow: public Window{
    public:
        explicit WindowsWindow(const WindowProps &props);
        ~WindowsWindow() override;

        void OnUpdate() override;

        inline unsigned int GetWidth() const override { return m_Data.Width; }
        inline unsigned int GetHeight() const override { return m_Data.Height; }

        // Window attributes
        inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
        void SetVSync(bool enabled) override;
        bool IsVSync() const override;

    private:
        virtual void Init(const WindowProps& props);
        virtual void Shutdown();

    private:
        GLFWwindow* m_Window;

        struct WindowData{
            std::string Title;
            unsigned int Width, Height;
            bool VSync;

            EventCallbackFn EventCallback;
        };

        WindowData m_Data;
    };
}

#endif //HAZELENGINE_WINDOWSWINDOW_H