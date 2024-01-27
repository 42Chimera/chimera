#ifndef CHIMERA_ENGINE_SOURCE_CORE_MOUSECODE_H
#define CHIMERA_ENGINE_SOURCE_CORE_MOUSECODE_H

namespace Cm
{
using MouseCode = uint16_t;
namespace Mouse
{
  enum : MouseCode
  {
    // glfw3.h
    Button0 = 0,
    Button1 = 1,
    Button2 = 2,
    Button3 = 3,
    Button4 = 4,
    Button5 = 5,
    Button6 = 6,
    Button7 = 7,

    ButtonLast = Button7,
    ButtonLeft = Button0,
    ButtonRight = Button1,
    ButtonMiddle = Button2
  };
}
}// namespace Cm
#endif
