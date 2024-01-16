#include "core/Window.h"
#include "platform/window/MacOSWindow.h"
#include "event/ApplicationEvent.h"

namespace Cm {

static bool sGLFWInitialized = false;

MacOSWindow::~MacOSWindow() { Shutdown(); }

MacOSWindow::MacOSWindow(const WindowProps& props) { Init(props); }

void MacOSWindow::Init(const WindowProps& props) {
  mData.Title = props.Title;
  mData.Width = props.Width;
  mData.Height = props.Height;

  CM_CORE_INFO("Creating Window {0} ({1} {2})", props.Title, props.Width,
               props.Height);

  if (!sGLFWInitialized) {
    int success = glfwInit();
  }

  mWindow = glfwCreateWindow(static_cast<int>(props.Width),
                             static_cast<int>(props.Height),
                             props.Title.c_str(), nullptr, nullptr);
  glfwMakeContextCurrent(mWindow);
  glfwSetWindowUserPointer(mWindow, &mData);
  SetVSync(true);

  glfwSetWindowCloseCallback(mWindow, [](GLFWwindow* window) {
    WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

    WindowCloseEvent event;
    data.EventCallBack(event);
  });
}
void MacOSWindow::Shutdown() { glfwDestroyWindow(mWindow); }

void MacOSWindow::OnUpdate() {
  glfwPollEvents();
  glfwSwapBuffers(mWindow);
}
void MacOSWindow::SetVSync(bool enabled) {
  if (enabled) {
    glfwSwapInterval(1);
  } else {
    glfwSwapInterval(0);
  }
  mData.VSync = enabled;
}
bool MacOSWindow::IsVSync() const { return mData.VSync; }
} // namespace Cm