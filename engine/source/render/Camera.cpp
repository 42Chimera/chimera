#include "render/Camera.h"
#include "render/PerspectiveProjection.h"
#include "glm/gtc/matrix_transform.hpp"
namespace Cm
{
Camera::Camera( glm::vec3 pos, glm::vec3 dir, glm::vec3 upDir, ProjectionType type, ProjectionInfo info )
{
  mCameraInfo.pos = pos;
  mCameraInfo.dir = dir;
  mCameraInfo.upDir = upDir;
  mCameraInfo.type = type;
  mPerspectiveProjection = std::make_unique<PerspectiveProjection>( info.fov, info.aspectRatio, info.near, info.far );
}

void Camera::UpdateCameraInfo()
{
  //TODO : 사용자 이벤트 or GUI를 통한 카메라 정보 변경을 반영하여 계산해 줘야될 값들
  // - 카메라 dir
  //
}

const glm::mat4& Camera::CalculateViewMatrix()
{
  UpdateCameraInfo();
  return glm::lookAt( mCameraInfo.pos, mCameraInfo.pos + mCameraInfo.dir, mCameraInfo.upDir );
}

const glm::mat4& Camera::CalculateViewProjectionMatrix()
{
  glm::mat4 view = CalculateViewMatrix();
  glm::mat4 projection;
  if ( mCameraInfo.type == ProjectionType::Orthogonal )
  {
    projection = mOrthogonalProjection->CalculateProjectionMaxtrix();
  }
  else
  {
    projection = mPerspectiveProjection->CalculateProjectionMaxtrix();
  }

  return projection * view;
}

}// namespace Cm