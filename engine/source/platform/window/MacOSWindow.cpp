#include "core/Window.h"
#include "platform/window/MacOSWindow.h"
#include "event/ApplicationEvent.h"
#include "event/KeyEvent.h"
#include "event/MouseEvent.h"

namespace Cm
{

static bool sGLFWInitialized = false;

MacOSWindow::~MacOSWindow()
{
  Shutdown();
}

MacOSWindow::MacOSWindow( const WindowProps& props )
{
  Init( props );
}

void MacOSWindow::Init( const WindowProps& props )
{
  mData.Title = props.Title;
  mData.Width = props.Width;
  mData.Height = props.Height;

  CM_CORE_INFO( "Creating Window {0} ({1} {2})", props.Title, props.Width, props.Height );

  if ( !sGLFWInitialized )
  {
    int success = glfwInit();
    if ( !success )
    {
      CM_CORE_CRITICAL( "glfw initialize fail" );
      exit( 1 );
    }
  }

  mWindow = glfwCreateWindow( static_cast<int>( props.Width ),
                              static_cast<int>( props.Height ),
                              props.Title.c_str(),
                              nullptr,
                              nullptr );
  glfwMakeContextCurrent( mWindow );
  glfwSetWindowUserPointer( mWindow, &mData );
  SetVSync( true );

  // set Event callback
  glfwSetWindowCloseCallback( mWindow, []( GLFWwindow* window )
                              {
    WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

    WindowCloseEvent event;
    data.EventCallBack(event); } );

  glfwSetWindowSizeCallback( mWindow, []( GLFWwindow* window, int width, int height )
                             {
                               WindowData& data = *(WindowData*)glfwGetWindowUserPointer( window );

                               data.Width = width;
                               data.Height = height;

                               WindowResizeEvent event(width, height);
                               data.EventCallBack( event ); } );

  glfwSetKeyCallback( mWindow, []( GLFWwindow* window, int key, int scancode, int action, int mods )
                      {
                        WindowData& data = *(WindowData*)glfwGetWindowUserPointer( window );
                        (void) scancode;
                        (void) mods;
                        switch (action)
                        {
                          case GLFW_PRESS:
                          {
                            KeyPressEvent event(key, false);
                            data.EventCallBack(event);
                            break;
                          }
                          case GLFW_RELEASE:
                          {
                            KeyReleasEvent event(key);
                            data.EventCallBack(event);
                            break;
                          }
                          case GLFW_REPEAT:
                          {
                            KeyPressEvent event(key, true);
                            data.EventCallBack(event);
                            break;
                          }
                        } } );

  glfwSetMouseButtonCallback( mWindow, []( GLFWwindow* window, int button, int action, int mods )
                              {
                                WindowData& data = *(WindowData*)glfwGetWindowUserPointer( window ); 
                                (void) mods;
                                switch (action)
                                {
                                  case GLFW_PRESS:
                                  {
                                    MouseButtonPressEvent event(button);
                                    data.EventCallBack(event);
                                    break;
                                  }
                                  case GLFW_RELEASE:
                                  {
                                    MouseButtonReleaseEvent event(button);
                                    data.EventCallBack(event);
                                    break;
                                  }
                                } } );

  glfwSetCursorPosCallback( mWindow, []( GLFWwindow* window, double xPos, double yPos )
                            {
                              WindowData& data = *(WindowData*)glfwGetWindowUserPointer( window );

                              MouseMoveEvent event(static_cast<float>(xPos), static_cast<float>(yPos));
                              data.EventCallBack(event); } );
}

void MacOSWindow::Shutdown()
{
  glfwDestroyWindow( mWindow );
}

void MacOSWindow::OnUpdate()
{
  glfwPollEvents();
  glfwSwapBuffers( mWindow );
}

void MacOSWindow::SetVSync( bool enabled )
{
  if ( enabled )
  {
    glfwSwapInterval( 1 );
  }
  else
  {
    glfwSwapInterval( 0 );
  }
  mData.VSync = enabled;
}

bool MacOSWindow::IsVSync() const
{
  return mData.VSync;
}
}// namespace Cm