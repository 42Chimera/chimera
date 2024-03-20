#ifndef CHIMERA_ENGINE_SOURCE_RENDER_INDEXBUFFER_H
#define CHIMERA_ENGINE_SOURCE_RENDER_INDEXBUFFER_H

#include "core/Pch.h"

namespace Cm
{
class CHIMERA_API IndexBuffer
{
public:
  virtual ~IndexBuffer() = default;

  virtual void Bind() const = 0;
  virtual void UnBind() const = 0;

  virtual void SetData( const void* data, uint32_t size ) const = 0;

  static std::shared_ptr<IndexBuffer> Create( uint32_t* indices, uint32_t size );
};
}// namespace Cm
#endif