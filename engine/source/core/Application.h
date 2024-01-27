#ifndef CHIMERA_ENGINE_SOURCE_CORE_APPLICATION_H
#define CHIMERA_ENGINE_SOURCE_CORE_APPLICATION_H

#include "core/Pch.h"
#include "internal/CmUtil.h"
#include "core/Window.h"
#include "event/Event.h"
#include "event/ApplicationEvent.h"
#include "core/LayerStack.h"
namespace Cm
{

class CHIMERA_API Application
{
public:
  Application();
  virtual ~Application() = default;

  void Run();

  void OnEvent( Event& event );

  void PushLayer( Layer* layer );
  void PushOverLay( Layer* overlay );

  static Application& Get()
  {
    return *sInstance;
  }
  inline Window& GetWindow()
  {
    return *mWindow;
  }

private:
  bool OnWindowCloseEvent( WindowCloseEvent& event );

private:
  std::unique_ptr<Window> mWindow;
  LayerStack mLayerStack;
  bool mRunning = true;

private:
  static Application* sInstance;
};

// To be defined in CLIENT
std::unique_ptr<Application> CreateApplication();
}// namespace Cm

#endif// CHIMERA_ENGINE_SOURCE_CORE_APPLICATION_H