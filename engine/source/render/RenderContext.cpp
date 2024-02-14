#include "render/RenderContext.h"
#include "platform/opengl/OpenGLRenderContext.h"
#include "render/Renderer.h"

namespace Cm
{
std::unique_ptr<RenderContext> RenderContext::Create( void* window )
{
  switch ( Renderer::GetAPI() )
  {
    case RenderAPI::API::OpenGL:
    {
      return std::make_unique<OpenGLRenderContext>( static_cast<GLFWwindow*>( window ) );
    }
    case RenderAPI::API::Direct3D:
    {
      CM_ASSERT_DEV( "박지윤", false, "Direct3D is not supported yet" );
      return nullptr;
    }
  }
  CM_ASSERT_DEV( "박지윤", false, "Not Supported Platform" );
  return nullptr;
}
}// namespace Cm