#include "render/PerspectiveProjection.h"
#include "glm/glm.hpp"
#include "glm/gtc/quaternion.hpp"
namespace Cm
{
PerspectiveProjection::PerspectiveProjection( float fov, float aspectRatio, float near, float far )
    : mFov( fov )
    , mAspectRatio( aspectRatio )
    , mNear( near )
    , mFar( far )
{
}

const glm::mat4& PerspectiveProjection::CalculateProjectionMaxtrix() const
{
  return glm::perspective( glm::radians( mFov ), mAspectRatio, mNear, mFar );
}
}// namespace Cm