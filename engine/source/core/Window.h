#ifndef CHIMERA_ENGINE_SOURCE_CORE_WINDOW_H
#define CHIMERA_ENGINE_SOURCE_CORE_WINDOW_H

#include "internal/CmUtil.h"
#include "core/Pch.h"
#include "event/Event.h"

namespace Cm
{
struct WindowProps
{
  WindowProps( const std::string& title = "Chimera Engine",
               uint32_t width = 1280,
               uint32_t height = 720 )
      : Title( title )
      , Width( width )
      , Height( height )
  {
  }
  std::string Title;
  uint32_t Width;
  uint32_t Height;
};

class CHIMERA_API Window
{
public:
  using EventCallBackFunction = std::function<void( Event& )>;

  virtual ~Window() = default;

  virtual void OnUpdate() = 0;

  virtual uint32_t GetWidth() const = 0;
  virtual uint32_t GetHeight() const = 0;

  virtual void SetEventCallBack( const EventCallBackFunction& callBack ) = 0;
  virtual void SetVSync( bool enabled ) = 0;
  virtual bool IsVSync() const = 0;

#undef CreateWindow
  static Window* CreateWindow( const WindowProps& props = WindowProps() );
};
}// namespace Cm
#endif