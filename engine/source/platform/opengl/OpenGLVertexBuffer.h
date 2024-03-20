#ifndef CHIMERA_ENGINE_SOURCE_PLATFORM_OPENGL_OPENGLVERTEXBUFFER_H
#define CHIMERA_ENGINE_SOURCE_PLATFORM_OPENGL_OPENGLVERTEXBUFFER_H

#include "render/VertexBuffer.h"

namespace Cm
{
class CHIMERA_API OpenGLVertexBuffer : public VertexBuffer
{
public:
  OpenGLVertexBuffer( float* vertices, uint32_t size );
  virtual ~OpenGLVertexBuffer();

  virtual void Bind() const override;
  virtual void UnBind() const override;

  virtual void SetData( const void* data, uint32_t size ) const override;

  virtual void SetLayout( const BufferLayout& layout ) override
  {
    mLayout = layout;
  }
  virtual const BufferLayout& GetLayout() const override
  {
    return mLayout;
  }

private:
  uint32_t mID;
  BufferLayout mLayout;
};
}// namespace Cm
#endif