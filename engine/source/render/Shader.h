#ifndef CHIMERA_ENGINE_SOURCE_RENDER_SHADER_H
#define CHIMERA_ENGINE_SOURCE_RENDER_SHADER_H

#include "core/Pch.h"

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

  static std::unique_ptr<Shader> Create( const std::string& vertexFilePath, const std::string& fragFilePath );
};
}// namespace Cm
#endif
