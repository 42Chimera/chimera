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
  const float cameraSpeed = 0.1f;
  const float cameraRotaionSpeed = 0.3f;
  if ( Input::IsKeyPressed( Key::LeftControl ) )
  {
    // keyboard event
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

    // mouse event
    if ( Input::IsMouseButtonPressed( Mouse::ButtonLeft ) )
    {
      glm::vec2 curMousePos = Input::GetMousePosition();
      glm::vec2 deltaPos = ( curMousePos - mPrevMousePos );
      mPrevMousePos = curMousePos;

      mCameraYaw -= deltaPos.x * cameraRotaionSpeed;
      mCameraPitch -= deltaPos.y * cameraRotaionSpeed;

      if ( mCameraYaw < 0.0f )
      {
        mCameraYaw += 360.0f;
      }
      if ( mCameraYaw > 360.0f )
      {
        mCameraYaw -= 360.0f;
      }
      if ( mCameraPitch > 89.0f )
      {
        mCameraPitch = 89.0f;
      }
      if ( mCameraPitch < -89.0f )
      {
        mCameraPitch = -89.0f;
      }
    }
    glm::mat4 rotation = glm::rotate( glm::mat4( 1.0f ), glm::radians( mCameraYaw ), glm::vec3( 0.0f, 1.0f, 0.0f ) ) * glm::rotate( glm::mat4( 1.0f ), glm::radians( mCameraPitch ), glm::vec3( 1.0f, 0.0f, 0.0f ) );
    mCameraFrontDir = rotation * glm::vec4( 0.0, 0.0f, -1.0f, 0.0f );
  }
}

glm::mat4 Camera::CalculateViewMatrix()
{
  UpdateCameraState();
  return glm::lookAt( mCameraPos, mCameraPos + mCameraFrontDir, mCameraUpDir );
}


bool Camera::OnMouseButtonPressEvent( MouseButtonPressEvent& event )
{
  if ( event.GetMouseButton() == Mouse::ButtonLeft )
  {
    mPrevMousePos = Input::GetMousePosition();
  }
  return false;
}

void Camera::OnEvent( Event& event )
{
  EventDispatcher dispatcher( event );

  dispatcher.Dispatch<MouseButtonPressEvent>( std::bind( &Camera::OnMouseButtonPressEvent, this, std::placeholders::_1 ) );
}

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