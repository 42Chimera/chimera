#include "core/Layer.h"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

namespace Cm
{
void Layer::DrawExample()
{
  ImGui::Begin( "Example" );
  ImGui::Text( "Hello, world!" );
  ImGui::End();
}
}// namespace Cm