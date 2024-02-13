#include "render/RenderAPI.h"
#include "platform/opengl/OpenGLRenderAPI.h"

namespace Cm
{
#if defined( CM_PLATFORM_MACOS ) || defined( CM_PLATFORM_WINDOWS )
RenderAPI::API RenderAPI::sAPI = RenderAPI::API::OpenGL;
#endif


std::unique_ptr<RenderAPI> RenderAPI::Create()
{
  switch ( sAPI )
  {
    case RenderAPI::API::OpenGL:
    {
      return std::make_unique<OpenGLRenderAPI>();
    }
    case RenderAPI::API::Direct3D:
    {
      CM_ASSERT_DEV( "박지윤", false, "Direx3D is not supported yet" );
      return nullptr;
    }
  }
  return nullptr;
}

RenderAPI::API RenderAPI::GetAPI()
{
  return sAPI;
}
}// namespace Cm