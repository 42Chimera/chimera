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
  mVertexArray = VertexArray::Create();

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

  mVertexBuffer = VertexBuffer::Create( vertices, sizeof( vertices ) );
  BufferLayout layout = { { "a_position", ShaderDataType::Float3, false } };
  mVertexBuffer->SetLayout( layout );
  mVertexArray->AddVertexBuffer( mVertexBuffer );

  unsigned int indices[3] = { 0, 1, 2 };
  mIndexBuffer = IndexBuffer::Create( indices, sizeof( indices ) );
  mVertexArray->SetIndexBuffer( mIndexBuffer );

  //init Shader
  mShader = Shader::Create( "../engine/asset/shader/simple.vs", "../engine/asset/shader/simple.fs" );

  // init camera
  ProjectionInfo projectionInfo = { 45.0f, (float)( mWindow->GetWidth() / mWindow->GetHeight() ), 0.1f, 10.0f };
  mCamera = std::make_unique<Camera>( glm::vec3( 1.0f, 1.0f, 3.0f ), glm::vec3( 0.0f, 0.0f, -1.0f ), glm::vec3( 0.0f, 1.0f, 0.0f ), ProjectionType::Perspective, projectionInfo );
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
    //Rendering Logic
    glClearColor( 0.1f, 0.1f, 0.1f, 1.0f );
    glClear( GL_COLOR_BUFFER_BIT );

    Renderer::BegineScene();
    mShader->Bind();
    Renderer::Submit( mVertexArray );
    Renderer::EndScene();

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