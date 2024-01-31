#ifndef CHIMERA_ENGINE_SOURCE_CORE_LAYERSTACK_H
#define CHIMERA_ENGINE_SOURCE_CORE_LAYERSTACK_H

#include "core/Layer.h"

namespace Cm
{
class CHIMERA_API LayerStack
{
public:
  LayerStack() = default;
  ~LayerStack();

  void PushLayer( Layer* layer );
  void PushOverlay( Layer* overlay );
  void PopLayer( Layer* layer );
  void PopOverlay( Layer* overlay );

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