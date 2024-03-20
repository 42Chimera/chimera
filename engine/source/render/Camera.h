#ifndef CHIMERA_ENGINE_SOURCE_RENDER_CAMERA_H
#define CHIMERA_ENGINE_SOURCE_RENDER_CAMERA_H

#include "core/Pch.h"
#include "glm/glm.hpp"
// 카메라는 데이터 집합임
// 카메라는 객체는 외부 객체에게 viewprojection matrix를 반환해주는 역할을 하면됨
// viewprojection matrix를 계산하는데 필요한 정보
// - 투영법
// - 투영법에 따라 필요한 데이터가 다름 (어떤걸 계산하는데 있어서 계산 전략이 다름)
//   - 투영방법 자체를 객체로 만들면 될듯

class CHIMERA_API Camera
{
public:
  glm::mat4 CalculateViewProjectionMatrix();
};
#endif
