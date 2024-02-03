#ifndef CHIMERA_ENGINE_SOURCE_IMGUI_IMGUILAYER_H
#define CHIMERA_ENGINE_SOURCE_IMGUI_IMGUILAYER_H

#include "core/Layer.h"

namespace Cm
{
class ImguiLayer : public Layer
{
public:
  CHIMERA_API ImguiLayer( const std::string& name );
  CHIMERA_API virtual void OnAttatch() override;
  CHIMERA_API virtual void OnDetach() override;
  CHIMERA_API virtual void OnImguiRender() override;

  CHIMERA_API void begin();
  CHIMERA_API void end();
};

}// namespace Cm
#endif
