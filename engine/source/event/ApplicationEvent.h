#ifndef CHIMERA_ENGINE_SOURCE_CORE_APPLICATIONEVENT_H
#define CHIMERA_ENGINE_SOURCE_CORE_APPLICATIONEVENT_H

#include "event/Event.h"

namespace Cm {
class CHIMERA_API WindowResizeEvent : public Event {
public:
  WindowResizeEvent(uint32_t width, uint32_t height)
      : mWidth(width), mHeight(height) {}
  inline uint32_t GetWidth() const { return mWidth; }
  inline uint32_t GetHeight() const { return mHeight; }

  std::string Tostring() const {
    std::stringstream ss;
    ss << "WindowResizeEvent: " << mWidth << ", " << mHeight;
    return ss.str();
  }

  EVENT_CLASS_TYPE(WindowResize)
  EVENT_CLASS_CATEGORY(EventCategoryApplication)

private:
  uint32_t mWidth;
  uint32_t mHeight;
};

class CHIMERA_API WindowCloseEvent : public Event {
public:
  WindowCloseEvent() {}

  std::string Tostring() const {
    std::stringstream ss;
    ss << "WindowCloseEvent";
    return ss.str();
  }

  EVENT_CLASS_TYPE(WindowClose)
  EVENT_CLASS_CATEGORY(EventCategoryApplication)
};
} // namespace Cm
#endif