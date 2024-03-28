#include "Chimera.h"

class ExampleLayer : public Cm::Layer
{
public:
  ExampleLayer()
      : Layer( "ExampleLayer" )
  {
  }
  void OnAttatch() override
  {
    mVertexArray = Cm::VertexArray::Create();
    // clang-format off
    std::vector<float> vertices = {
    -0.5f, -0.5f, -0.5f,
     0.5f, -0.5f, -0.5f,
     0.5f,  0.5f, -0.5f,
    -0.5f,  0.5f, -0.5f,
    -0.5f, -0.5f,  0.5f,
     0.5f, -0.5f,  0.5f,
     0.5f,  0.5f,  0.5f,
    -0.5f,  0.5f,  0.5f,
    -0.5f,  0.5f,  0.5f,
    -0.5f,  0.5f, -0.5f,
    -0.5f, -0.5f, -0.5f,
    -0.5f, -0.5f,  0.5f,
     0.5f,  0.5f,  0.5f,
     0.5f,  0.5f, -0.5f,
     0.5f, -0.5f, -0.5f,
     0.5f, -0.5f,  0.5f,
    -0.5f, -0.5f, -0.5f,
     0.5f, -0.5f, -0.5f,
     0.5f, -0.5f,  0.5f,
    -0.5f, -0.5f,  0.5f,
    -0.5f,  0.5f, -0.5f,
     0.5f,  0.5f, -0.5f,
     0.5f,  0.5f,  0.5f,
    -0.5f,  0.5f,  0.5f,
    };
    // clang-format on
    mVertexBuffer = Cm::VertexBuffer::Create( vertices.data(), vertices.size() * sizeof( float ) );
    Cm::BufferLayout layout = { { "a_position", Cm::ShaderDataType::Float3, false } };
    mVertexBuffer->SetLayout( layout );
    mVertexArray->AddVertexBuffer( mVertexBuffer );

    // clang-format off
    std::vector<uint32_t> indices = {
     0,  2,  1,  2,  0,  3,
     4,  5,  6,  6,  7,  4,
     8,  9, 10, 10, 11,  8,
    12, 14, 13, 14, 12, 15,
    16, 17, 18, 18, 19, 16,
    20, 22, 21, 22, 20, 23,
    };
    // clang-format on
    mIndexBuffer = Cm::IndexBuffer::Create( indices.data(), indices.size() );
    mVertexArray->SetIndexBuffer( mIndexBuffer );

    //init Shader
    mShader = Cm::Shader::Create( "./engine/asset/shader/simple.vs", "./engine/asset/shader/simple.fs" );

    // init camera
    mCamera = std::make_unique<Cm::Camera>();
  }
  void OnDetach() override
  {
  }
  void OnUpdate() override
  {
    //Rendering Logic
    Cm::RenderCommand::SetClearColor( { 0.1f, 0.1f, 0.1f, 1.0f } );
    Cm::RenderCommand::ClearColor();

    Cm::Renderer::BegineScene( mCamera );
    Cm::Renderer::Submit( mShader, mVertexArray );
    Cm::Renderer::EndScene();
  }

  void OnEvent( Cm::Event& event ) override
  {
    mCamera->OnEvent( event );
  }
  virtual void OnImguiRender() override
  {
    DrawExample();
  }

private:
  std::shared_ptr<Cm::VertexBuffer> mVertexBuffer;
  std::shared_ptr<Cm::IndexBuffer> mIndexBuffer;
  std::shared_ptr<Cm::VertexArray> mVertexArray;
  std::unique_ptr<Cm::Shader> mShader;
  std::unique_ptr<Cm::Camera> mCamera;
};

class Scop : public Cm::Application
{
public:
  Scop()
      : Application()
  {
    PushLayer( new ExampleLayer() );
  }
};

std::unique_ptr<Cm::Application> Cm::CreateApplication()
{
  return std::make_unique<Scop>();
}

int main( int ac, char** av )
{
  (void)ac;
  (void)av;
  Cm::Logger::Init();
  CM_CLIENT_INFO( "SCOP START!!" );
  auto scop = Cm::CreateApplication();
  scop->Run();
  return 0;
}
