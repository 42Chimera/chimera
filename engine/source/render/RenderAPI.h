#ifndef CHIMERA_ENGINE_SOURCE_RENDERAPI_H
#define CHIMERA_ENGINE_SOURCE_RENDERAPI_H

#include <glm/glm.hpp>
#include "core/Pch.h"
#include "render/VertexArray.h"

namespace Cm
{
class CHIMERA_API RenderAPI
{
public:
  enum class API
  {
    OpenGL = 0,
    Direct3D = 1,
  };

  RenderAPI() = default;
  virtual ~RenderAPI() = default;

  virtual void SetViewPort( uint32_t x, uint32_t y, uint32_t width, uint32_t height ) const = 0;
  virtual void SetClearColor( const glm::vec4& color ) const = 0;
  virtual void ClearColor() const = 0;

  virtual void DrawElement( const std::shared_ptr<VertexArray>& vertexArray, uint32_t count ) const = 0;


  static std::unique_ptr<RenderAPI> Create();
  static API GetAPI();

private:
  static API sAPI;
};
}// namespace Cm

#endif
