#include "core/Time.h"

namespace Cm
{
std::chrono::high_resolution_clock::time_point Time::GetCurrentTime()
{
  return std::chrono::high_resolution_clock::now();
}
}// namespace Cm