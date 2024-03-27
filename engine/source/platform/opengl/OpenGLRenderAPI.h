#ifndef CHIMERA_ENGINE_SOUCE_PLATFORM_OPENGL_OPENGLRENDERAPI_H
#define CHIMERA_ENGINE_SOUCE_PLATFORM_OPENGL_OPENGLRENDERAPI_H

#include "core/Pch.h"
#include "render/RenderAPI.h"
namespace Cm
{
class CHIMERA_API OpenGLRenderAPI : public RenderAPI
{
public:
  OpenGLRenderAPI() = default;
  virtual ~OpenGLRenderAPI() = default;

  virtual void Init() const override;
  virtual void SetViewPort( uint32_t x, uint32_t y, uint32_t width, uint32_t height ) const override;
  virtual void SetClearColor( const glm::vec4& color ) const override;
  virtual void ClearColor() const override;

  virtual void DrawElement( const std::shared_ptr<VertexArray>& vertexArray ) const override;
};
}// namespace Cm
#endif
