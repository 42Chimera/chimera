#include "render/Shader.h"
#include "render/Renderer.h"
#include "platform/opengl/OpenGLShader.h"

namespace Cm
{
std::unique_ptr<Shader> Shader::Create( const std::string& vertexFilePath, const std::string& fragFilePath )
{
  switch ( Renderer::GetAPI() )
  {
    case RenderAPI::API::OpenGL:
    {
      return OpenGLShader::Create( vertexFilePath, fragFilePath );
    }
    case RenderAPI::API::Direct3D:
    {
      CM_ASSERT_DEV( "박지윤", false, "Direct3D is not supported yet" );
      return nullptr;
    }
  }
  return nullptr;
}
}// namespace Cm