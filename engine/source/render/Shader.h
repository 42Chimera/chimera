#ifndef CHIMERA_ENGINE_SOURCE_RENDER_SHADER_H
#define CHIMERA_ENGINE_SOURCE_RENDER_SHADER_H

#include "core/Pch.h"
#include "glm/glm.hpp"
namespace Cm
{

enum class ShaderType : uint32_t
{
  Vertex = 0,
  Fragment = 1,
};
class CHIMERA_API Shader
{
public:
  virtual ~Shader() = default;

  virtual void Bind() = 0;
  virtual void Unbind() = 0;

  virtual void SetUniformMat4( const std::string& name, const glm::mat4& matrix ) = 0;

  static std::unique_ptr<Shader> Create( const std::string& vertexFilePath, const std::string& fragFilePath );
};
}// namespace Cm
#endif
