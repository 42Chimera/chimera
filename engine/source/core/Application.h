#pragma once
#ifndef CHIMERA_ENGINE_SOURCE_CORE_APPLICATION_H
#define CHIMERA_ENGINE_SOURCE_CORE_APPLICATION_H

// system
#include <memory>

// extern
#include "GLFW/glfw3.h"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

// intern
#include "internal/CmUtil.h"

struct GLFWwindow;

namespace Cm
{

/**
 * (1) Application은 Window를 자식으로 가지면 안된다. 둘은 별도이다.
 */
class CHIMERA_API Application : private NonCopyable
{
public:
  Application(int argc, char** argv) noexcept;
  virtual ~Application() noexcept;
  bool Init() noexcept;

public:
  int Run() noexcept;
  int Reboot() noexcept;
  int Shutdown() noexcept;

private:
  bool mRunning;
  // NOTE: 새로운 윈도우를 만드는 경우는 프로세스를 하나 더 파는 경우 뿐.
  // 그럼 fork된 프로세스에서, 윈도우 루프를 새롭게 돌거 아닌가.
};


} // namespace Cm

#endif //CHIMERA_ENGINE_SOURCE_CORE_APPLICATION_H