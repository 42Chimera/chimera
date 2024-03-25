#include "core/Pch.h"
#include "glad/glad.h"
#include "internal/CmUtil.h"
#include "core/Application.h"
#include "render/RenderCommnad.h"
#include "render/Renderer.h"

namespace Cm
{

Application::Application()
{
  CM_ASSERT_DEV( "jinypark", ( !sInstance ), "Application already exists" );
  sInstance = this;
  mWindow = std::unique_ptr<Window>( Window::CreateWindow() );
  mWindow->SetEventCallBack(
  std::bind( &Application::OnEvent, this, std::placeholders::_1 ) );

  mImguiLayer = new ImguiLayer( "Imgui_Layer" );
  PushOverLay( mImguiLayer );

  Renderer::Init();
  RenderCommand::SetViewPort( 0, 0, mWindow->GetWidth(), mWindow->GetHeight() );
}


void Application::OnEvent( Event& event )
{
  EventDispatcher dispatcher( event );
  dispatcher.Dispatch<WindowCloseEvent>(
  std::bind( &Application::OnWindowCloseEvent, this, std::placeholders::_1 ) );
  //TODO: OnWindowResizeEvent 추가

  for ( auto it = mLayerStack.rbegin(); it != mLayerStack.rend(); ++it )
  {
    if ( event.Handled )
    {
      break;
    }
    ( *it )->OnEvent( event );
  }
}

void Application::Run()
{
  CM_CORE_INFO( "Run Start" );
  while ( mRunning )
  {
    for ( auto it = mLayerStack.begin(); it != mLayerStack.end(); ++it )
    {
      ( *it )->OnUpdate();
    }

    //Render Imgui thing in layer
    mImguiLayer->begin();
    for ( auto it = mLayerStack.begin(); it != mLayerStack.end(); ++it )
    {
      ( *it )->OnImguiRender();
    }
    mImguiLayer->end();

    mWindow->OnUpdate();
  }
}

void Application::PushLayer( Layer* layer )
{
  mLayerStack.PushLayer( layer );
  layer->OnAttatch();
}

void Application::PushOverLay( Layer* overlay )
{
  mLayerStack.PushOverlay( overlay );
  overlay->OnAttatch();
}

bool Application::OnWindowCloseEvent( WindowCloseEvent& event )
{
  (void)event;
  mRunning = false;
  return true;
}
}// namespace Cm