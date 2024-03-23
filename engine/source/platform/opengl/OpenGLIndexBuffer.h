#ifndef CHIMERA_ENGINE_SOURCE_PLATFORM_OPENGL_OPENGLINDEXBUFFER_H
#define CHIMERA_ENGINE_SOURCE_PLATFORM_OPENGL_OPENGLINDEXBUFFER_H

#include "render/IndexBuffer.h"
namespace Cm
{
class CHIMERA_API OpenGLIndexBuffer : public IndexBuffer
{
public:
  OpenGLIndexBuffer( uint32_t* indices, uint32_t size );
  virtual ~OpenGLIndexBuffer();

  virtual void Bind() const override;
  virtual void UnBind() const override;

  virtual void SetData( const void* data, uint32_t size ) const override;
  virtual uint32_t GetSize() const override
  {
    return mSize;
  }

private:
  uint32_t mID;
  uint32_t mSize;
};
}// namespace Cm
#endif