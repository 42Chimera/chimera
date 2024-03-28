#include "core/Time.h"

namespace Cm
{
float Time::GetCurrentTime()
{
  auto curTime = std::chrono::high_resolution_clock::now();

  std::chrono::duration<float> durationSinceEpoch = curTime.time_since_epoch();
  return durationSinceEpoch.count();
}
}// namespace Cm