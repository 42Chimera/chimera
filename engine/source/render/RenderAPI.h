#ifndef CHIMERA_ENGINE_SOURCE_RENDERAPI_H
#define CHIMERA_ENGINE_SOURCE_RENDERAPI_H

#include "core/Pch.h"

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

  static std::unique_ptr<RenderAPI> Create();
  static API GetAPI();

private:
  static API sAPI;
};
}// namespace Cm

#endif
