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
  DeltaTime( float time );

  float GetSecond() const;
  float GetMiliSecond() const;

private:
  float mTime;// second in float
};
}// namespace Cm
#endif
