#ifndef CHIMERA_ENGINE_SOURCE_CORE_TIME_H
#define CHIMERA_ENGINE_SOURCE_CORE_TIME_H

#include "core/Pch.h"

namespace Cm
{
class CHIMERA_API Time
{
public:
  static std::chrono::high_resolution_clock::time_point GetCurrentTime();
};
}// namespace Cm
#endif
