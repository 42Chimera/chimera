#ifndef CHIMERA_ENGINE_SOURCE_RENDER_PERSPECTIVEPROJECTION_H
#define CHIMERA_ENGINE_SOURCE_RENDER_PERSPECTIVEPROJECTION_H

#include "render/Projection.h"

namespace Cm
{
class CHIMERA_API PerspectiveProjection : public Projection
{
public:
  PerspectiveProjection( float fov, float aspectRatio, float near, float far );
  glm::mat4 CalculateProjectionMaxtrix() const;


  // TODO : viewport size 변경에 따른 aspectRatio Set 함수 필요
private:
  float mFov;
  float mAspectRatio;
  float mNear;
  float mFar;
};
}// namespace Cm

#endif
