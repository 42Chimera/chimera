#include "core/Application.h"
#include "core/Input.h"
#include "GLFW/glfw3.h"

namespace Cm
{
bool Input::IsKeyPressed( KeyCode key )
{
  auto* window = static_cast<GLFWwindow*>( Application::Get().GetWindow().GetNativeWindow() );
  int32_t state = glfwGetKey( window, static_cast<int32_t>( key ) );
  return state == GLFW_PRESS;
}

bool Input::IsMouseButtonPressed( MouseCode button )
{
  auto* window = static_cast<GLFWwindow*>( Application::Get().GetWindow().GetNativeWindow() );
  int32_t state = glfwGetMouseButton( window, static_cast<int32_t>( button ) );
  return state == GLFW_PRESS;
}

glm::vec2 Input::GetMousePosition()
{
  auto* window = static_cast<GLFWwindow*>( Application::Get().GetWindow().GetNativeWindow() );
  double xPos, yPos;
  glfwGetCursorPos( window, &xPos, &yPos );
  return { static_cast<float>( xPos ), static_cast<float>( yPos ) };
}

float Input::GetMouseX()
{
  return GetMousePosition().x;
}

float Input::GetMouseY()
{
  return GetMousePosition().y;
}
}// namespace Cm