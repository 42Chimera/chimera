#ifndef CHIMERA_ENGINE_SOURCE_CORE_LAYER_H
#define CHIMERA_ENGINE_SOURCE_CORE_LAYER_H

#include "internal/CmUtil.h"
#include "event/Event.h"

namespace Cm
{
class CHIMERA_API Layer
{
public:
  Layer( const std::string& name = "Layer" );
  virtual ~Layer() = default;

  virtual void OnAttatch() = 0;
  virtual void OnDetach() = 0;
  virtual void OnUpdate() {}
  virtual void OnImguiRender() {}
  virtual void OnEvent( Event& event )
  {
    (void)event;
  }

  inline const std::string GetName() const
  {
    return mName;
  }

private:
  std::string mName;
};

}// namespace Cm
#endif