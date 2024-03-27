#include "platform/opengl/OpenGLRenderAPI.h"
#include "glad/glad.h"

namespace Cm
{

void OpenGLRenderAPI::Init() const
{
  glEnable( GL_DEPTH_TEST );
}
void OpenGLRenderAPI::SetViewPort( uint32_t x, uint32_t y, uint32_t width, uint32_t height ) const
{
  glViewport( x, y, width, height );
}
void OpenGLRenderAPI::SetClearColor( const glm::vec4& color ) const
{
  glClearColor( color.r, color.g, color.b, color.a );
}
void OpenGLRenderAPI::ClearColor() const
{
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}
void OpenGLRenderAPI::DrawElement( const std::shared_ptr<VertexArray>& vertexArray ) const
{
  vertexArray->Bind();
  glDrawElements( GL_TRIANGLES, vertexArray->GetIndexBuffer()->GetSize(), GL_UNSIGNED_INT, nullptr );
}
}// namespace Cm