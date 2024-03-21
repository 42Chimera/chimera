#ifndef CHIMERA_ENGINE_SOURCE_RENDER_PERSPECTIVEPROJECTION_H
#define CHIMERA_ENGINE_SOURCE_RENDER_PERSPECTIVEPROJECTION_H

#include "render/Projection.h"

class CHIMERA_API PerspectiveProjection : public Projection
{
public:
  PerspectiveProjection( float fov, float aspectRatio, float near, float far );
  const glm::mat4& CalculateProjectionMaxtrix() const;

private:
  float mFov;
  float mAspectRatio;
  float mNear;
  float mFar;
};

#endif
