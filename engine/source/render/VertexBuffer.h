#ifndef CHIMERA_ENGINE_SOURCE_RENDER_VERTEXBUFFER_H
#define CHIMERA_ENGINE_SOURCE_RENDER_VERTEXBUFFER_H

#include "core/Pch.h"
#include "render/Buffer.h"

namespace Cm
{
class CHIMERA_API VertexBuffer
{
public:
  virtual ~VertexBuffer() = default;

  virtual void Bind() const = 0;
  virtual void UnBind() const = 0;

  virtual void SetData( const void* data, uint32_t size ) const = 0;

  virtual void SetLayout( const BufferLayout& layout ) = 0;
  virtual const BufferLayout& GetLayout() const = 0;

  static std::shared_ptr<VertexBuffer> Create( float* vertices, uint32_t size );
};
}// namespace Cm
#endif
