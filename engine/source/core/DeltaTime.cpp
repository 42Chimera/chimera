#include "core/DeltaTime.h"

namespace Cm
{
DeltaTime::DeltaTime()
    : mTime()
{
}

DeltaTime::DeltaTime( float time )
    : mTime( time )
{
}

float DeltaTime::GetSecond() const
{
  return mTime;
}
float DeltaTime::GetMiliSecond() const
{
  return mTime * (float)1000;
}
}// namespace Cm