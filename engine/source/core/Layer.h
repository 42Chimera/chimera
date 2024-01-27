#ifndef CHIMERA_ENGINE_SOURCE_CORE_LAYER_H
#define CHIMERA_ENGINE_SOURCE_CORE_LAYER_H


#include "event/Event.h"
#include "internal/CmUtil.h"

namespace Cm
{
class CHIMERA_API Layer
{
public:
  Layer( const std::string& name = "Layer" );

  virtual void OnAttatch() = 0;
  virtual void OnDetach() = 0;
  virtual void OnUpdate() {}
  virtual void OnImguiRender() {}
  virtual void OnEvent( Event& event ) {}

  inline const std::string GetName() const
  {
    return mName;
  }

private:
  std::string mName;
};

}// namespace Cm
#endif