#include "core/Pch.h"

#include "internal/CmUtil.h"
#include "core/Application.h"

extern bool g_ApplicationRunning;
static Cm::Application* s_Instance = nullptr; // Single instance

static void glfw_error_callback(int error_code, const char* description) noexcept
{
  CM_CORE_ERROR("GLFW Error {0}: {1}", error_code, description);
}

namespace Cm {

Application::Application(int argc, char** argv) noexcept
{
  if (s_Instance==nullptr) // 이미 app이 하나 켜져있으면 더이상 키지 말 것!
  {
    s_Instance = this;
    Init();
  }
  else {
    LOG_ERROR("Duplicate Application instance");
    assert(false);
  }
}

Application::~Application() noexcept
{
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();

  glfwDestroyWindow(m_Window.Handle); // TODO: change this...
  glfwTerminate();

  s_Instance = nullptr;
}

int Application::Run() noexcept
{
  mRunning = true;
  while (42)
  {
    // ...
  }
}

bool Application::Init() noexcept
{
  // Setup GLFW window
  glfwSetErrorCallback(glfw_error_callback);
  if (!glfwInit()) // Init GLFW
  {
    CM_CORE_ERROR("GLFW initialization failed...");
    return false;
  }
  // Setup GLFW window properties
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // OpenGL major version
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); // OpenGL minor version
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // Core profile = No Backwards Compatibility
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // Allow forward compatibility
//  glfwGetMonitorWorkarea(glfwGetPrimaryMonitor(), &xpos, &ypos, NULL, &height);
}

} // namespace Cm