#ifndef CHIMERA_ENGINE_SOURCE_CORE_INPUT_H
#define CHIMERA_ENGINE_SOURCE_CORE_INPUT_H

#include "core/Pch.h"
#include "internal/CmUtil.h"
#include "core/KeyCode.h"
#include "core/MouseCode.h"

#include "glm/glm.hpp"

namespace Cm
{
class CHIMERA_API Input
{
public:
  static bool IsKeyPressed( KeyCode key );
  static bool IsMouseButtonPressed( MouseCode button );

  static glm::vec2 GetMousePosition();
  static float GetMouseX();
  static float GetMouseY();
};

}// namespace Cm
#endif
