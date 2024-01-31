#ifndef CHIMERA_ENGINE_SOURCE_IMGUI_IMGUILAYER_H
#define CHIMERA_ENGINE_SOURCE_IMGUI_IMGUILAYER_H

#include "core/Layer.h"

namespace Cm
{
class CHIMERA_API ImguiLayer : public Layer
{
public:
  ImguiLayer( const std::string& name );
  virtual void OnAttatch() override;
  virtual void OnDetach() override;
  virtual void OnImguiRender() override;

  void begin();
  void end();
};

}// namespace Cm
#endif
