#ifndef CHIMERA_ENGINE_SOURCE_PLATFORM_OPENGL_OPENGLRENDERCONTEXT_H
#define CHIMERA_ENGINE_SOURCE_PLATFORM_OPENGL_OPENGLRENDERCONTEXT_H

#include "GLFW/glfw3.h"

#include "render/RenderContext.h"
namespace Cm
{
class CHIMERA_API OpenGLRenderContext : public RenderContext
{
public:
  OpenGLRenderContext( GLFWwindow* window );
  virtual ~OpenGLRenderContext() = default;
  virtual void Init() override;
  virtual void SwapBuffer() override;

private:
  GLFWwindow* mWindowHandle;
};
}// namespace Cm
#endif