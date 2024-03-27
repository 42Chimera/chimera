#include "render/Camera.h"
#include "render/PerspectiveProjection.h"
#include "glm/gtc/matrix_transform.hpp"
#include "core/Input.h"
namespace Cm
{
Camera::Camera( glm::vec3 pos, glm::vec3 dir, glm::vec3 upDir, ProjectionType type, ProjectionInfo info )
{
  mCameraInfo.pos = pos;
  mCameraInfo.dir = dir;
  mCameraInfo.upDir = upDir;
  mCameraInfo.type = type;
  mPerspectiveProjection = std::make_unique<PerspectiveProjection>( info.fov, info.aspectRatio, info.nearClip, info.farClip );
}

void Camera::UpdateCameraInfo()
{
  //TODO : 사용자 이벤트 or GUI를 통한 카메라 정보 변경을 반영하여 계산해 줘야될 값들
  const float cameraSpeed = 0.1;
  glm::vec3 cameraFrontDir = glm::normalize( mCameraInfo.dir );
  if ( Input::IsKeyPressed( Key::W ) )
  {
    mCameraInfo.pos += cameraSpeed * cameraFrontDir;
  }
  if ( Input::IsKeyPressed( Key::S ) )
  {
    mCameraInfo.pos -= cameraSpeed * cameraFrontDir;
  }
  glm::vec3 cameraRightDir = glm::normalize( glm::cross( mCameraInfo.upDir, -mCameraInfo.dir ) );
  if ( Input::IsKeyPressed( Key::A ) )
  {
    mCameraInfo.pos -= cameraSpeed * cameraRightDir;
  }
  if ( Input::IsKeyPressed( Key::D ) )
  {
    mCameraInfo.pos += cameraSpeed * cameraRightDir;
  }
  glm::vec3 cameraUpDir = glm::normalize( glm::cross( cameraRightDir, cameraFrontDir ) );
  if ( Input::IsKeyPressed( Key::E ) )
  {
    mCameraInfo.pos += cameraSpeed * cameraUpDir;
  }
  if ( Input::IsKeyPressed( Key::Q ) )
  {
    mCameraInfo.pos -= cameraSpeed * cameraUpDir;
  }
}

glm::mat4 Camera::CalculateViewMatrix()
{
  UpdateCameraInfo();
  return glm::lookAt( mCameraInfo.pos, mCameraInfo.pos + mCameraInfo.dir, mCameraInfo.upDir );
}

glm::mat4 Camera::CalculateViewProjectionMatrix()
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