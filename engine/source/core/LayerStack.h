#ifndef CHIMERA_ENGINE_SOURCE_CORE_LAYERSTACK_H
#define CHIMERA_ENGINE_SOURCE_CORE_LAYERSTACK_H

#include "core/Layer.h"

namespace Cm
{
class LayerStack
{
public:
  LayerStack() = default;
  CHIMERA_API ~LayerStack();

  CHIMERA_API void PushLayer( Layer* layer );
  CHIMERA_API void PushOverlay( Layer* overlay );
  CHIMERA_API void PopLayer( Layer* layer );
  CHIMERA_API void PopOverlay( Layer* overlay );

  std::vector<Layer*>::iterator begin()
  {
    return mLayers.begin();
  }
  std::vector<Layer*>::iterator end()
  {
    return mLayers.end();
  }

  std::vector<Layer*>::const_iterator begin() const
  {
    return mLayers.begin();
  }
  std::vector<Layer*>::const_iterator end() const
  {
    return mLayers.end();
  }

  std::vector<Layer*>::reverse_iterator rbegin()
  {
    return mLayers.rbegin();
  }
  std::vector<Layer*>::reverse_iterator rend()
  {
    return mLayers.rend();
  }

  std::vector<Layer*>::const_reverse_iterator rbegin() const
  {
    return mLayers.rbegin();
  }
  std::vector<Layer*>::const_reverse_iterator rend() const
  {
    return mLayers.rend();
  }

private:
  std::vector<Layer*> mLayers;
  uint32_t mLayerInsertIndex = 0;
};
}// namespace Cm
#endif