#include "render/IndexBuffer.h"
#include "render/Renderer.h"
#include "platform/opengl/OpenGLIndexBuffer.h"

namespace Cm
{
std::shared_ptr<IndexBuffer> IndexBuffer::Create( float* indices, uint32_t size )
{
  switch ( Renderer::GetAPI() )
  {
    case RenderAPI::API::OpenGL:
    {
      return std::make_shared<OpenGLIndexBuffer>( indices, size );
    }
    case RenderAPI::API::Direct3D:
    {
      CM_ASSERT_DEV( "박지윤", false, "not supported reder api!" );
      return nullptr;
    }
  }
  CM_ASSERT_DEV( "박지윤", false, "not supported reder api!" );
  return nullptr;
}
}// namespace Cm