#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"
#include "GLFW/glfw3.h"

#include "source/imgui/ImguiLayer.h"
#include "core/Application.h"

namespace Cm
{
ImguiLayer::ImguiLayer( const std::string& name )
    : Layer( name )
{
}

//from imgui/example
void ImguiLayer::OnAttatch()
{
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO& io = ImGui::GetIO();
  io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;// Enable Keyboard Controls
  io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad; // Enable Gamepad Controls
  io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;    // Enable Docking
  io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;  // Enable Multi-Viewport / Platform Windows

  // Setup Dear ImGui style
  ImGui::StyleColorsDark();

  // When viewports are enabled we tweak WindowRounding/WindowBg so platform windows can look identical to regular ones.
  ImGuiStyle& style = ImGui::GetStyle();
  if ( io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable )
  {
    style.WindowRounding = 0.0f;
    style.Colors[ImGuiCol_WindowBg].w = 1.0f;
  }

  // Setup Platform/Renderer backends
  Application& app = Application::Get();
  GLFWwindow* window = static_cast<GLFWwindow*>( app.GetWindow().GetNativeWindow() );
  ImGui_ImplGlfw_InitForOpenGL( window, true );
  ImGui_ImplOpenGL3_Init();
}

void ImguiLayer::OnDetach()
{
  // Cleanup
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();
}

void ImguiLayer::OnUpdate() {}

void ImguiLayer::begin()
{
  // Start the Dear ImGui frame
  ImGui_ImplOpenGL3_NewFrame();
  ImGui_ImplGlfw_NewFrame();
  ImGui::NewFrame();
}

void ImguiLayer::end()
{
  ImGuiIO& io = ImGui::GetIO();
  Application& app = Application::Get();
  io.DisplaySize = ImVec2( static_cast<float>( app.GetWindow().GetWidth() ), static_cast<float>( app.GetWindow().GetHeight() ) );

  ImGui::Render();
  ImGui_ImplOpenGL3_RenderDrawData( ImGui::GetDrawData() );
  if ( io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable )
  {
    GLFWwindow* backup_current_context = glfwGetCurrentContext();
    ImGui::UpdatePlatformWindows();
    ImGui::RenderPlatformWindowsDefault();
    glfwMakeContextCurrent( backup_current_context );
  }
}

void ImguiLayer::OnImguiRender()
{
  static bool showDemoWindow = true;
  ImGui::ShowDemoWindow( &showDemoWindow );
}
}// namespace Cm