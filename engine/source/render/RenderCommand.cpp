#include "render/RenderCommnad.h"
#include "glad/glad.h"

namespace Cm
{
std::unique_ptr<RenderAPI> RenderCommand::sRenderAPI = RenderAPI::Create();

void RenderCommand::Init()
{
  sRenderAPI->Init();
}
void RenderCommand::SetViewPort( uint32_t x, uint32_t y, uint32_t width, uint32_t height )
{
  sRenderAPI->SetViewPort( x, y, width, height );
}
void RenderCommand::SetClearColor( const glm::vec4& color )
{
  sRenderAPI->SetClearColor( color );
}
void RenderCommand::ClearColor()
{
  sRenderAPI->ClearColor();
}
void RenderCommand::DrawIndex( const std::shared_ptr<VertexArray>& vertexArray )
{
  sRenderAPI->DrawElement( vertexArray );
}
}// namespace Cm