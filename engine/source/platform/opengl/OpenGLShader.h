#ifndef CHIMERA_ENGINE_SOURCE_PLATFORM_OPENGL_OPENGLSHADER_H
#define CHIMERA_ENGINE_SOURCE_PLATFORM_OPENGL_OPENGLSHADER_H

#include "render/Shader.h"

namespace Cm
{
class CHIMERA_API OpenGLShader : public Shader
{
public:
  static std::unique_ptr<OpenGLShader> Create( const std::string& vertexFilePath, const std::string& fragFilePathkj );
  virtual void Bind() override;
  virtual void Unbind() override;

private:
  OpenGLShader() = default;
  bool Init( const std::string& vertexFilePath, const std::string& fragFilePath );
  std::optional<std::string> LoadFromFile( const std::string& filePath );

private:
  uint32_t mProgramID;
};
}// namespace Cm
#endif
