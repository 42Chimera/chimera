#ifndef CHIMERA_ENGINE_SOURCE_RENDERCOMMAND_H
#define CHIMERA_ENGINE_SOURCE_RENDERCOMMAND_H

#include "render/RenderAPI.h"


namespace Cm
{
class CHIMERA_API RenderCommand
{
public:
  static void SetViewPort( uint32_t x, uint32_t y, uint32_t width, uint32_t height );
  static void SetClearColor( const glm::vec4& color );
  static void ClearColor();
  static void DrawIndex( const std::shared_ptr<VertexArray>& vertexArray );

private:
  static std::unique_ptr<RenderAPI> sRenderAPI;
};
}// namespace Cm
#endif
