#ifndef CHIMERA_ENGINE_SOURCE_EVENT_EVENT_H
#define CHIMERA_ENGINE_SOURCE_EVENT_EVENT_H

#include "core/Pch.h"
#include "internal/CmUtil.h"

namespace Cm
{
// EventType
enum class EventType
{
  None = 0,
  WindowClose,
  WindowResize,
  KeyPress,
  KeyRelease,
  MouseMove,
  MouseButtonPress,
  MouseButtonRelease
};

// EvnetCategory
enum EventCategory
{
  None = 0,
  EventCategoryApplication = ( 1 << 0 ),
  EventCategoryInput = ( 1 << 1 ),
  EventCategoryKeyBoard = ( 1 << 2 ),
  EventCategoryMouse = ( 1 << 3 ),
  EventCategoryMouseButton = ( 1 << 4 )
};

#define EVENT_CLASS_CATEGORY( category )        \
  virtual int GetCategoryFlags() const override \
  {                                             \
    return category;                            \
  }

#define EVENT_CLASS_TYPE( type )                  \
  static EventType GetStaticType()                \
  {                                               \
    return EventType::type;                       \
  }                                               \
  virtual EventType GetEventType() const override \
  {                                               \
    return GetStaticType();                       \
  }                                               \
  virtual const char* GetName() const override    \
  {                                               \
    return #type;                                 \
  }

class CHIMERA_API Event
{
public:
  virtual ~Event() = default;
  virtual EventType GetEventType() const = 0;
  virtual const char* GetName() const = 0;
  virtual int GetCategoryFlags() const = 0;
  virtual std::string ToString() const
  {
    return GetName();
  }

  inline bool IsInCategory( EventCategory category )
  {
    return GetCategoryFlags() & category;
  }

  bool Handled = false;
};

class CHIMERA_API EventDispatcher
{
  template<typename T>
  using EventFunction = std::function<bool( T& )>;

public:
  EventDispatcher( Event& event )
      : mEvent( event )
  {
  }

  template<typename T>
  bool Dispatch( EventFunction<T> func )
  {
    if ( mEvent.GetEventType() == T::GetStaticType() )
    {
      mEvent.Handled |= func( static_cast<T&>( mEvent ) );
      return true;
    }
    return false;
  }

private:
  Event& mEvent;
};

// logger event 정보 출력시 필요
inline std::ostream& operator<<( std::ostream& os, const Event& event )
{
  return os << event.ToString();
}
}// namespace Cm
#endif