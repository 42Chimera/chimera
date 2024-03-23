#ifndef CHIMERA_ENGINE_SOURCE_VERTEXARRAY_H
#define CHIMERA_ENGINE_SOURCE_VERTEXARRAY_H

#include "core/Pch.h"
#include "render/VertexBuffer.h"
#include "render/IndexBuffer.h"
namespace Cm
{
class CHIMERA_API VertexArray
{
public:
  virtual ~VertexArray() = default;

  virtual void Bind() const = 0;
  virtual void UnBind() const = 0;

  virtual void AddVertexBuffer( const std::shared_ptr<VertexBuffer>& vertexbuffer ) = 0;
  virtual void SetIndexBuffer( const std::shared_ptr<IndexBuffer>& indexbuffer ) = 0;
  virtual const std::shared_ptr<IndexBuffer>& GetIndexBuffer() const = 0;
  static std::shared_ptr<VertexArray> Create();
};
}// namespace Cm
#endif