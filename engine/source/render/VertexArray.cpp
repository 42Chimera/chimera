#include "render/VertexArray.h"
#include "render/Renderer.h"
#include "platform/opengl/OpenGLVertexArray.h"
namespace Cm
{
std::shared_ptr<VertexArray> VertexArray::Create()
{
  switch ( Renderer::GetAPI() )
  {
    case RenderAPI::API::OpenGL:
    {
      return std::make_shared<OpenGLVertexArray>();
    }
    case RenderAPI::API::Direct3D:
    {
      CM_ASSERT_DEV( "박지윤", false, "not supported render API!" );
      return nullptr;
    }
  }
  CM_ASSERT_DEV( "박지윤", false, "not supported render API!" );
  return nullptr;
}
}// namespace Cm