#ifndef CHIMERA_ENGINE_SOURCE_RENDER_CAMERA_H
#define CHIMERA_ENGINE_SOURCE_RENDER_CAMERA_H

#include "glm/glm.hpp"

#include "core/Pch.h"
#include "render/Projection.h"
#include "event/Event.h"
#include "event/MouseEvent.h"
// 카메라는 데이터 집합임
// 카메라는 객체는 외부 객체에게 viewprojection matrix를 반환해주는 역할을 하면됨
// viewprojection matrix를 계산하는데 필요한 정보
//
// 카메라는 카메라의 위치 및 방향 정보를 통해 view matrix를 계산 할 수 있음
// - 투영법
// - 투영법에 따라 필요한 데이터가 다름 (어떤걸 계산하는데 있어서 계산 전략이 다름)
//   - 투영방법 자체를 객체로 만들면 될듯
//   - 투영방법은 ui를 통해 언제든 변경 할 수 있음
namespace Cm
{
enum class ProjectionType
{
  Orthogonal = 0,
  Perspective,
};

class CHIMERA_API Camera
{
public:
  Camera();
  ~Camera() = default;

  glm::mat4 CalculateViewProjectionMatrix();

  void OnEvent( Event& event );

  // TODO : imgui를 통한 camera 정보 udpate를 위해 접근자 필요
private:
  glm::mat4
  CalculateViewMatrix();
  void UpdateCameraState();
  bool OnMouseButtonPressEvent( MouseButtonPressEvent& event );

private:
  glm::vec3 mCameraPos = { 0.0f, 0.0f, 3.0f };
  glm::vec3 mCameraFrontDir = { 0.0f, 0.0f, -1.0f };
  glm::vec3 mCameraUpDir = { 0.0f, 1.0f, 0.0f };
  float mCameraYaw = 0.0f;
  float mCameraPitch = 0.0f;
  ProjectionType mCameraType = ProjectionType::Perspective;

  float mFov = 45.0f;
  float mAspectRatio = 1.778f;
  float mNearClip = 0.1f;
  float mFarClip = 10.0f;

  glm::vec2 mPrevMousePos = { 0.0f, 0.0f };

  std::unique_ptr<Projection> mOrthogonalProjection;
  std::unique_ptr<Projection> mPerspectiveProjection;
};
}// namespace Cm
#endif
