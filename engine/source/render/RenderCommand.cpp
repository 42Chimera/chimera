#include "render/RenderCommnad.h"

namespace Cm
{
std::unique_ptr<RenderAPI> RenderCommand::sRenderAPI = RenderAPI::Create();


void RenderCommand::SetViewPort( uint32_t x, uint32_t y, uint32_t width, uint32_t height )
{
}
void RenderCommand::SetClearColor( const glm::vec4& color ) {}
void RenderCommand::ClearColor() {}
void RenderCommand::DrawElement( const std::shared_ptr<VertexArray>& vertexArray, uint32_t count ) {}

}// namespace Cm