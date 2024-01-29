#ifndef CHIMERA_ENGINE_SOURCE_EVENT_KEYEVENT_H
#define CHIMERA_ENGINE_SOURCE_EVENT_KEYEVENT_H

#include "event/Event.h"
#include "core/KeyCode.h"

namespace Cm
{
class CHIMERA_API KeyEvent : public Event
{
public:
  KeyCode GetKeyCode() const
  {
    return mKeyCode;
  }
  EVENT_CLASS_CATEGORY( EventCategoryKeyBoard | EventCategoryInput )
protected:
  KeyEvent( const KeyCode keyCode )
      : mKeyCode( keyCode )
  {
  }
  KeyCode mKeyCode;
};

class CHIMERA_API KeyPressEvent : public KeyEvent
{
public:
  KeyPressEvent( const KeyCode keyCode, bool isRepeat = false )
      : KeyEvent( keyCode )
      , mIsRepeat( isRepeat )
  {
  }

  bool IsRepeat() const
  {
    return mIsRepeat;
  }

  virtual std::string ToString() const override
  {
    std::stringstream ss;
    ss << "KeyPressEvent : " << mKeyCode << "[ repeated : " << mIsRepeat << " ]";
    return ss.str();
  }

  EVENT_CLASS_TYPE( KeyPress )

private:
  bool mIsRepeat;
};

class CHIMERA_API KeyReleasEvent : public KeyEvent
{
public:
  KeyReleasEvent( const KeyCode keyCode )
      : KeyEvent( keyCode )
  {
  }

  virtual std::string ToString() const override
  {
    std::stringstream ss;
    ss << "KeyReleaseEvent : " << mKeyCode;
    return ss.str();
  }

  EVENT_CLASS_TYPE( KeyRelease )
};
}// namespace Cm
#endif
