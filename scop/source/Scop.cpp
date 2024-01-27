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
