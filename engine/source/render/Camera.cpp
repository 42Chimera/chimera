#include "render/Camera.h"
#include "render/PerspectiveProjection.h"
#include "glm/gtc/matrix_transform.hpp"
#include "core/Input.h"
namespace Cm
{
Camera::Camera()
{
  mPerspectiveProjection = std::make_unique<PerspectiveProjection>( mFov, mAspectRatio, mNearClip, mFarClip );
}

void Camera::UpdateCameraState()
{
  //TODO : 사용자 이벤트 or GUI를 통한 카메라 정보 변경을 반영하여 계산해 줘야될 값들
  const float cameraSpeed = 0.1;
  if ( Input::IsKeyPressed( Key::LeftControl ) )
  {
    glm::vec3 cameraFrontDir = glm::normalize( mCameraFrontDir );
    if ( Input::IsKeyPressed( Key::W ) )
    {
      mCameraPos += cameraSpeed * cameraFrontDir;
    }
    if ( Input::IsKeyPressed( Key::S ) )
    {
      mCameraPos -= cameraSpeed * cameraFrontDir;
    }
    glm::vec3 cameraRightDir = glm::normalize( glm::cross( mCameraUpDir, -mCameraFrontDir ) );
    if ( Input::IsKeyPressed( Key::A ) )
    {
      mCameraPos -= cameraSpeed * cameraRightDir;
    }
    if ( Input::IsKeyPressed( Key::D ) )
    {
      mCameraPos += cameraSpeed * cameraRightDir;
    }
    glm::vec3 cameraUpDir = glm::normalize( glm::cross( cameraRightDir, cameraFrontDir ) );
    if ( Input::IsKeyPressed( Key::E ) )
    {
      mCameraPos += cameraSpeed * cameraUpDir;
    }
    if ( Input::IsKeyPressed( Key::Q ) )
    {
      mCameraPos -= cameraSpeed * cameraUpDir;
    }
  }
}

glm::mat4 Camera::CalculateViewMatrix()
{
  UpdateCameraState();
  return glm::lookAt( mCameraPos, mCameraPos + mCameraFrontDir, mCameraUpDir );
}

void Camera::OnEvent( Event& event ) {}

glm::mat4 Camera::CalculateViewProjectionMatrix()
{
  glm::mat4 view = CalculateViewMatrix();
  glm::mat4 projection;
  if ( mCameraType == ProjectionType::Orthogonal )
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