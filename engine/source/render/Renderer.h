#ifndef CHIMERA_ENGINE_SOURCE_RENDER_RENDERER_H
#define CHIMERA_ENGINE_SOURCE_RENDER_RENDERER_H

#include "glm/glm.hpp"

#include "core/Pch.h"
#include "RenderAPI.h"
#include "render/camera.h"
namespace Cm
{
// static class
// - 클라이언트에서 해당 지점을 통해 렌더링 과정을 불러옴
class CHIMERA_API Renderer
{
public:
  static void BegineScene();
  static void EndScene();
  static void Submit( const std::shared_ptr<VertexArray>& vertexArray );
  static RenderAPI::API GetAPI();

private:
  // Renderer가 가지고 있어야 하는 상태
  // - 씬 정보
  //    - 현재 씬의 VP matrix
  glm::mat4 mViewProjectionMatrix;  
};
}// namespace Cm
#endif
