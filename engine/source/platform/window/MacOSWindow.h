#ifndef CHIMERA_ENGINE_SOURCE_PLATFORM_WINDOW_MACOSWINDOW_H
#define CHIMERA_ENGINE_SOURCE_PLATFORM_WINDOW_MACOSWINDOW_H

#include "internal/CmUtil.h"
#include "core/Pch.h"
#include "core/Window.h"
#include "render/RenderContext.h"
#include "GLFW/glfw3.h"

namespace Cm
{
class MacOSWindow : public Window
{
public:
  MacOSWindow( const WindowProps& props );
  virtual ~MacOSWindow();

  void OnUpdate() override;

  inline uint32_t GetWidth() const override
  {
    return mData.Width;
  }
  inline uint32_t GetHeight() const override
  {
    return mData.Height;
  }

  inline void SetEventCallBack( const EventCallBackFunction& callBack ) override
  {
    mData.EventCallBack = callBack;
  }
  void SetVSync( bool enabled ) override;
  bool IsVSync() const override;

  virtual void* GetNativeWindow() const override
  {
    return mWindow;
  }

private:
  void Init( const WindowProps& props );
  void Shutdown();

  GLFWwindow* mWindow;
  std::unique_ptr<RenderContext> mRenderContext;
  struct WindowData
  {
    std::string Title;
    uint32_t Width, Height;
    bool VSync;

    EventCallBackFunction EventCallBack;
  };

  WindowData mData;
};
}// namespace Cm
#endif