#include "core/Pch.h"

#include "internal/CmUtil.h"
#include "core/Application.h"

namespace Cm
{

Application* Application::sInstance = nullptr;

Application::Application()
{
  sInstance = this;
  mWindow = std::unique_ptr<Window>( Window::CreateWindow() );
  mWindow->SetEventCallBack(
  std::bind( &Application::OnEvent, this, std::placeholders::_1 ) );
}

void Application::OnEvent( Event& event )
{
  CM_CORE_TRACE( "{0}", event );

  EventDispatcher dispatcher( event );
  dispatcher.Dispatch<WindowCloseEvent>(
  std::bind( &Application::OnWindowCloseEvent, this, std::placeholders::_1 ) );

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