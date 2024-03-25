#ifndef CHIMERA_ENGINE_SOURCE_RENDER_PROJECTION_H
#define CHIMERA_ENGINE_SOURCE_RENDER_PROJECTION_H

#include "core/Pch.h"
#include "glm/glm.hpp"


class CHIMERA_API Projection
{
public:
  Projection() = default;
  virtual ~Projection() = default;
  virtual glm::mat4 CalculateProjectionMaxtrix() const = 0;
};
#endif
