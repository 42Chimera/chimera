#include "core/Window.h"
#include "platform/window/MacOSWindow.h"

namespace Cm {

Window* Window::CreateWindow(const WindowProps& props) {
#ifdef CM_PLATFORM_MACOS
  return new MacOSWindow(props);
#elif CM_PLATFORM_WINDOWS
  return new WindowsWindow(props);
#else
  CM_ASSERT_COMPILE("Platform Error : ", false, "not supported platform");
  return nullptr;
#endif
}

} // namespace Cm