#ifndef CHIMERA_ENGINE_SOURCE_CORE_MOUSEEVENT_H
#define CHIMERA_ENGINE_SOURCE_CORE_MOUSEEVENT_H

#include "event/Event.h"
#include "core/MouseCode.h"

namespace Cm
{
class CHIMERA_API MouseMoveEvent : public Event
{
public:
  MouseMoveEvent( const float x, const float y )
      : mX( x )
      , mY( y )
  {
  }

  float GetX() const
  {
    return mX;
  }

  float GetY() const
  {
    return mY;
  }

  virtual std::string ToString() const override
  {
    std::stringstream ss;
    ss << "MouseMoveEvent : " << mX << ", " << mY;
    return ss.str();
  }

  EVENT_CLASS_CATEGORY( EventCategoryInput | EventCategoryMouse )
  EVENT_CLASS_TYPE( MouseMove )

private:
  float mX, mY;
};

class CHIMERA_API MouseButtonEvent : public Event
{
public:
  MouseCode GetMouseButton() const
  {
    return mButton;
  }

  EVENT_CLASS_CATEGORY( EventCategoryInput | EventCategoryMouseButton )
protected:
  MouseButtonEvent( const MouseCode button )
      : mButton( button )
  {
  }
  MouseCode mButton;
};

class CHIMERA_API MouseButtonPressEvent : public MouseButtonEvent
{
public:
  MouseButtonPressEvent( const MouseCode button )
      : MouseButtonEvent( button )
  {
  }

  virtual std::string ToString() const override
  {
    std::stringstream ss;
    ss << "MouseButtonPressEvent : " << mButton;
    return ss.str();
  }

  EVENT_CLASS_TYPE( MouseButtonPress )
};

class CHIMERA_API MouseButtonReleaseEvent : public MouseButtonEvent
{
public:
  MouseButtonReleaseEvent( const MouseCode button )
      : MouseButtonEvent( button )
  {
  }

  virtual std::string ToString() const override
  {
    std::stringstream ss;
    ss << "MouseButtonReleaseEvent : " << mButton;
    return ss.str();
  }

  EVENT_CLASS_TYPE( MouseButtonRelease )
};
}// namespace Cm

#endif
