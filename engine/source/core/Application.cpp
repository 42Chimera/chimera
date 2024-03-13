#include "core/Pch.h"
#include "glad/glad.h"
#include "internal/CmUtil.h"
#include "core/Application.h"

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

  // glViewport( 0, 0, mWindow.get()->GetWidth(), mWindow.get()->GetHeight() );
  glGenVertexArrays( 1, &mVertexBufferArray );
  glBindVertexArray( mVertexBufferArray );

  float vertices[9] = {
  -0.5f,
  -0.5f,
  0.0f,
  0.5f,
  -0.5f,
  0.0f,
  0.0f,
  0.5f,
  0.0f };

  glGenBuffers( 1, &mVertexBuffer );
  glBindBuffer( GL_ARRAY_BUFFER, mVertexBuffer );
  glBufferData( GL_ARRAY_BUFFER, sizeof( vertices ), vertices, GL_STATIC_DRAW );

  glEnableVertexAttribArray( 0 );
  glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof( float ), (const void*)nullptr );


  unsigned int indices[3] = { 0, 1, 2 };
  glGenBuffers( 1, &mIndexBuffer );
  glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, mIndexBuffer );
  glBufferData( GL_ELEMENT_ARRAY_BUFFER, sizeof( indices ), indices, GL_STREAM_DRAW );

  mShader = Shader::Create( "../engine/asset/shader/simple.vs", "../engine/asset/shader/simple.fs" );
}

void Application::OnEvent( Event& event )
{
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
    glClearColor( 0.1f, 0.1f, 0.1f, 1.0f );
    glClear( GL_COLOR_BUFFER_BIT );

    mShader->Bind();
    glBindVertexArray( mVertexBufferArray );
    glDrawElements( GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr );
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