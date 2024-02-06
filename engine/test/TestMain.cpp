#include "Chimera.h"

class ExampleLayer : public Cm::Layer
{
public:
  ExampleLayer()
      : Layer( "ExampleLayer" )
  {
  }
  void OnUpdate() override
  {
  }

  void OnEvent( Cm::Event& event ) override
  {
    CM_CLIENT_TRACE( "{0}", event );
  }
  virtual void OnImguiRender() override
  {
    ImGui::Begin( "Test" );
    ImGui::Text( "Hello!!" );
    ImGui::End();
  }
};

class TestMain : public Cm::Application
{
public:
  TestMain()
      : Application()
  {
    PushLayer( new ExampleLayer() );
  }
};

std::unique_ptr<Cm::Application> Cm::CreateApplication()
{
  return std::make_unique<TestMain>();
}

int main( int ac, char** av )
{
  (void)ac;
  (void)av;
  Cm::Logger::Init();
  CM_CLIENT_INFO( "SCOP START!!" );
  auto program = Cm::CreateApplication();
  program->Run();
  return 0;
}
