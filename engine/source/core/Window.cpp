//
// Created by 김민규 on 2024-01-18.
//

#include "Window.h"

// 참고
// https://github.com/kimminkyeu/MiniBlender/blob/uv_map_viewer/Lunar/Core/Application.cpp

namespace Cm
{
    Window::Window(CmString title, CmPoint location, CmSize winSize) noexcept
    {}

    Window::~Window() noexcept
    {}



    bool Window::Init() noexcept
    {
      mWindowHandle = glfwCreateWindow(mWindowSize.mWidth, mWindowSize.mHeight, mName, nullptr, nullptr);
//      assert(m_Window.Handle && "GLFW window creation failed");
      // set the current context
      glfwMakeContextCurrent(m_WindowHandle); // Set context for GLEW to use (그럼 multiple context 존재? 여러 화면?)
    }

    void Window::Show() noexcept
    {}

    void Window::OnCloseEvent(Event& event) noexcept
    {}

    void Window::OnResizeEvent(Event& event) noexcept
    {}

    GLFWwindow* Window::GetWindowHandle() const noexcept
    {}
}