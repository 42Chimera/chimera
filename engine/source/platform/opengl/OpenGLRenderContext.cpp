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

  CM_CORE_INFO( "opengl : " );
  CM_CORE_INFO( "  vendor : {0}", (char*)glGetString( GL_VENDOR ) );
  CM_CORE_INFO( "  Renderer : {0}", (char*)glGetString( GL_RENDERER ) );
  CM_CORE_INFO( "  version : {0}", (char*)glGetString( GL_VERSION ) );
}

void OpenGLRenderContext::SwapBuffer()
{
  glfwSwapBuffers( mWindowHandle );
}
}// namespace Cm