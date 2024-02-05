#include "glad/glad.h"
#include "platform/opengl/OpenGLRenderContext.h"
namespace Cm
{
OpenGLRenderContext::OpenGLRenderContext( GLFWwindow* window )
    : mWindowHandle( window )
{
}

void OpenGLRenderContext::Init()
{
  glfwMakeContextCurrent( mWindowHandle );
  int status = gladLoadGLLoader( (GLADloadproc)glfwGetProcAddress );
  CM_ASSERT_DEV( "박지윤", status, "glad init failed!" );
}

void OpenGLRenderContext::SwapBuffer()
{
  glfwSwapBuffers( mWindowHandle );
}
}// namespace Cm