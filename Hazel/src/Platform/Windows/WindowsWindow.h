//
// Created by Npchitman on 2021/1/20.

#ifndef HAZELENGINE_WINDOWSWINDOW_H
#define HAZELENGINE_WINDOWSWINDOW_H

#include "Hazel/Core/Window.h"

struct GLFWwindow;

namespace Hazel {

    class WindowsWindow : public Window {

    public:
        explicit WindowsWindow(const WindowProps &props);

        ~WindowsWindow() override;

        void OnUpdate() override;

        unsigned int GetWidth() const override { return m_Data.Width; }

        unsigned int GetHeight() const override { return m_Data.Height; }

        void SetEventCallback(const EventCallbackFn &callback) override {
            m_Data.EventCallback = callback;
        }

        void SetVSync(bool enabled) override;

        bool IsVSync() const override;

        void *GetNativeWindow() const override { return m_Window; }

    private:
        // 初始化
        void Init(const WindowProps &props);

        // 关闭
        void Shutdown();

    private:
        GLFWwindow *m_Window;

        struct WindowData {
            std::string Title;
            unsigned int Width, Height;
            bool VSync;

            EventCallbackFn EventCallback;
        };

        WindowData m_Data;
    };

}// namespace Hazel

#endif// HAZELENGINE_WINDOWSWINDOW_H
