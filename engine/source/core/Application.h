#ifndef CHIMERA_ENGINE_SOURCE_CORE_APPLICATION_H
#define CHIMERA_ENGINE_SOURCE_CORE_APPLICATION_H

#include "core/Pch.h"
#include "internal/CmUtil.h"
#include "core/Window.h"
#include "event/Event.h"
#include "event/ApplicationEvent.h"
#include "core/LayerStack.h"
#include "imgui/ImguiLayer.h"
#include "render/Shader.h"
#include "render/VertexArray.h"
#include "render/VertexBuffer.h"
#include "render/IndexBuffer.h"
#include "render/Camera.h"
#include "render/Renderer.h"
namespace Cm
{
class Application
{
public:
  CHIMERA_API Application();
  virtual ~Application() = default;

  CHIMERA_API void Run();

  CHIMERA_API void OnEvent( Event& event );

  CHIMERA_API void PushLayer( Layer* layer );
  CHIMERA_API void PushOverLay( Layer* overlay );

  static Application& Get()
  {
    return *sInstance;
  }

  inline Window& GetWindow()
  {
    return *mWindow;
  }

private:
  CHIMERA_API bool OnWindowCloseEvent( WindowCloseEvent& event );

private:
  inline static Application* sInstance;
  std::unique_ptr<Window> mWindow;
  ImguiLayer* mImguiLayer;
  LayerStack mLayerStack;
  bool mRunning = true;

  std::shared_ptr<VertexBuffer> mVertexBuffer;
  std::shared_ptr<IndexBuffer> mIndexBuffer;
  std::shared_ptr<VertexArray> mVertexArray;
  std::unique_ptr<Shader> mShader;
  std::unique_ptr<Camera> mCamera;
};

// To be defined in CLIENT
std::unique_ptr<Application> CreateApplication();
}// namespace Cm


#endif// CHIMERA_ENGINE_SOURCE_CORE_APPLICATION_H