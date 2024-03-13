#include "render/VertexBuffer.h"
#include "render/Renderer.h"
#include "platform/opengl/OpenGLVertexBuffer.h"
namespace Cm
{
std::shared_ptr<VertexBuffer> VertexBuffer::Create( float* vertices, uint32_t size )
{
  switch ( Renderer::GetAPI() )
  {
    case RenderAPI::API::OpenGL:
      return std::make_shared<OpenGLVertexBuffer>( vertices, size );
    case RenderAPI::API::Direct3D:
      CM_ASSERT_DEV( false, "Not supported RenderAPI!" );
      return nullptr;
  }
  CM_ASSERT_DEV( false, "Not supported RenderAPI!" );
  return nullptr;
}
}// namespace Cm