//
// Created by 김민규 on 2024-01-18.
//

#ifndef SCOP_WINDOW_H
#define SCOP_WINDOW_H

#include "GLFW/glfw3.h"

#include "core/Pch.h"
#include "internal/CmUtil.h"

using CmString = std::string;
Class CmPoint
{
public: explicit CmPoint(int x, int y) noexcept
  : mX(x), mY(y) {}// int 쓰는게 맞나?
private:
  int mX;
  int mY;
};

Class CmSize
{
public: explicit CmSize(int width, int height) noexcept
  : mWidth(width), mHeight(height) {}// int 쓰는게 맞나?
private:
  int mWidth;
  int mHeight;
};


// 아래 내용 참고할 것.
//https://github.com/kimminkyeu/MiniBlender/blob/uv_map_viewer/Lunar/Core/Application.cpp
//https://github.com/glfw/glfw/blob/master/examples/windows.c --> multiple glfw window
//

class Event; // forward decl

namespace Cm
{
// move to CmTypes

// (0) 윈도우도 하나의 UI위젯이다. 윈도우도 State을 가진다.
// (1) 윈도우가 여러개일 경우, 윈도우 하나가 꺼져도 앱은 꺼지지 않는다.
//      그러나 메인 윈도우가 꺼지면 앱이 꺼진다.
class CHIMERA_API Window
{

public:
  Window(CmString title, CmPoint location, CmSize winSize) noexcept;
  ~Window() noexcept;

  void Show() noexcept;

  // Events
  void OnResizeEvent(Event& event) noexcept;
  void OnCloseEvent(Event& event) noexcept;

//    https://github.com/kimminkyeu/MiniBlender/blob/uv_map_viewer/Lunar/Core/Application.cpp

public:
    virtual bool Init() noexcept; // override this.

    GLFWwindow* GetWindowHandle() const noexcept;

// ------------- Member Data ----------
private:
    CmString mWindowTitle = "No Name";
    CmPoint mWindowLocation = CmPoint(0, 0);
    CmSize mWindowSize = CmSize(500, 500);
private:
    GLFWwindow* mWindowHandle = nullptr;
    GLint mBufferWidth = 0;
    GLint mBufferHeight = 0;
};

}

#endif // SCOP_WINDOW_H
