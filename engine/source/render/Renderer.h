#ifndef CHIMERA_ENGINE_SOURCE_RENDER_RENDERER_H
#define CHIMERA_ENGINE_SOURCE_RENDER_RENDERER_H

#include "core/Pch.h"
#include "RenderAPI.h"
namespace Cm
{
// static class
// - 클라이언트에서 해당 지점을 통해 렌더링 과정을 불러올 수 있
class CHIMERA_API Renderer
{
public:
  static RenderAPI::API GetAPI();
};
}// namespace Cm
#endif
