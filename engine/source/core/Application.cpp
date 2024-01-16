#include "core/Pch.h"

#include "internal/CmUtil.h"
#include "core/Application.h"

namespace Cm {

Application::Application() {
  mWindow = std::unique_ptr<Window>(Window::CreateWindow());
  mWindow->SetEventCallBack(
      std::bind(&Application::OnEvent, this, std::placeholders::_1));
}

void Application::OnEvent(Event& event) {
  CM_CORE_TRACE("{0}", event);

  EventDispatcher dispatcher(event);
  dispatcher.Dispatch<WindowCloseEvent>(
      std::bind(&Application::OnWindowCloseEvent, this, std::placeholders::_1));
}
void Application::Run() {
  CM_CORE_INFO("Run Start");
  while (mRunning) {
    mWindow->OnUpdate();
  }
}

bool Application::OnWindowCloseEvent(WindowCloseEvent& event) {
  mRunning = false;
  return true;
}
} // namespace Cm