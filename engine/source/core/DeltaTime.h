#ifndef CHIMERA_ENGINE_SOURCE_CORE_DELTATIME_H
#define CHIMERA_ENGINE_SOURCE_CORE_DELTATIME_H

#include <chrono>

#include "core/Pch.h"

namespace Cm
{
class CHIMERA_API DeltaTime
{
public:
  DeltaTime();

private:
  std::chrono::high_resolution_clock::time_point mTime;
};
}// namespace Cm
#endif
