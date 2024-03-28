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

  virtual void OnAttatch() = 0;
  virtual void OnDetach() = 0;
  virtual void OnUpdate( DeltaTime dt ) = 0;
  virtual void OnImguiRender() = 0;
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