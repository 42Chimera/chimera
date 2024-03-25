#include "core/LayerStack.h"

namespace Cm
{
LayerStack::~LayerStack()
{
  for ( Layer* layer : mLayers )
  {
    layer->OnDetach();
    delete layer;
  }
}
void LayerStack::PushLayer( Layer* layer )
{
  CM_ASSERT_DEV( "박지윤", ( layer != nullptr ), "layer should not be null" );
  mLayers.emplace( mLayers.begin() + mLayerInsertIndex, layer );
  layer->OnAttatch();
}

void LayerStack::PushOverlay( Layer* overlay )
{
  CM_ASSERT_DEV( "박지윤", ( overlay != nullptr ), "layer should not be null" );
  mLayers.emplace_back( overlay );
  overlay->OnAttatch();
}

void LayerStack::PopLayer( Layer* layer )
{
  CM_ASSERT_DEV( "박지윤", ( layer != nullptr ), "layer should not be null" );
  auto it =
  std::find( mLayers.begin(), mLayers.begin() + mLayerInsertIndex, layer );
  if ( it != mLayers.begin() + mLayerInsertIndex )
  {
    layer->OnDetach();
    mLayers.erase( it );
    mLayerInsertIndex--;
  }
}

void LayerStack::PopOverlay( Layer* overlay )
{
  CM_ASSERT_DEV( "박지윤", ( overlay != nullptr ), "layer should not be null" );
  auto it =
  std::find( mLayers.begin() + mLayerInsertIndex, mLayers.end(), overlay );
  if ( it != mLayers.end() )
  {
    overlay->OnDetach();
    mLayers.erase( it );
  }
}
}// namespace Cm