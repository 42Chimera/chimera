#ifndef CHIMERA_ENGINE_SOURCE_RENDER_CAMERA_H
#define CHIMERA_ENGINE_SOURCE_RENDER_CAMERA_H

#include "glm/glm.hpp"

#include "core/Pch.h"
#include "render/Projection.h"
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

struct ProjectionInfo
{
  float fov;
  float aspectRatio;
  float nearClip;
  float farClip;
};

class CHIMERA_API Camera
{
public:
  Camera( glm::vec3 pos, glm::vec3 dir, glm::vec3 upDir, ProjectionType type, ProjectionInfo info );
  ~Camera() = default;

  glm::mat4 CalculateViewProjectionMatrix();

  // TODO : imgui를 통한 camera 정보 udpate를 위해 접근자 필요
private:
  glm::mat4 CalculateViewMatrix();
  void UpdateCameraInfo();

private:
  struct CameraInfo
  {
    glm::vec3 pos;
    glm::vec3 dir;
    glm::vec3 upDir;
    float yaw;
    float pitch;
    ProjectionType type;
  };
  std::unique_ptr<Projection> mOrthogonalProjection;
  std::unique_ptr<Projection> mPerspectiveProjection;
  CameraInfo mCameraInfo;
};
}// namespace Cm
#endif
