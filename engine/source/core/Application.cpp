#include "core/Pch.h"
#include "glad/glad.h"
#include "internal/CmUtil.h"
#include "core/Application.h"
#include "render/RenderCommnad.h"
#include "render/Renderer.h"

namespace Cm
{

Application::Application()
    : mLastFrameTime( Time::GetCurrentTime() )
{
  CM_ASSERT_DEV( "jinypark", ( !sInstance ), "Application already exists" );
  sInstance = this;
  mWindow = std::unique_ptr<Window>( Window::CreateWindow() );
  mWindow->SetVSync( true );
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
    float curFrameTime = Time::GetCurrentTime();
    DeltaTime dt = DeltaTime( curFrameTime - mLastFrameTime );
    mLastFrameTime = curFrameTime;

    CM_CORE_TRACE( "fps : {0} second, {1} miliSecond", dt.GetSecond(), dt.GetMiliSecond() );

    for ( auto it = mLayerStack.begin(); it != mLayerStack.end(); ++it )
    {
      ( *it )->OnUpdate( dt );
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