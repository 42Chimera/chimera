#ifndef CHIMERA_ENGINE_SOURCE_RENDER_RENDERCONTEXT_H
#define CHIMERA_ENGINE_SOURCE_RENDER_RENDERCONTEXT_H

#include "core/Pch.h"
namespace Cm
{
class CHIMERA_API RenderContext
{
public:
  RenderContext() = default;
  virtual ~RenderContext() = default;

  virtual void Init() = 0;
  virtual void SwapBuffer() = 0;

  static std::unique_ptr<RenderContext> Create( void* window );
};
}// namespace Cm
#endif
