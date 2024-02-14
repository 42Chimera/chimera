#ifndef CHIMERA_ENGINE_SOURCE_CORE_LAYER_H
#define CHIMERA_ENGINE_SOURCE_CORE_LAYER_H

#include "internal/CmUtil.h"
#include "event/Event.h"

namespace Cm
{
class Layer
{
public:
  Layer( const std::string& name = "Layer" )
      : mName( name )
  {
  }

  virtual ~Layer() = default;

  virtual void OnAttatch() {}
  virtual void OnDetach() {}
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

  CHIMERA_API void DrawExample();

private:
  std::string mName;
};


}// namespace Cm
#endif