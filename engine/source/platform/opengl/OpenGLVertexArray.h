#ifndef CHIMERA_ENGINE_SOURCE_PLATFORM_OPENGL_OPENGLVERTEXARRAY_H
#define CHIMERA_ENGINE_SOURCE_PLATFORM_OPENGL_OPENGLVERTEXARRAY_H
#include "render/VertexArray.h"
namespace Cm
{
class CHIMERA_API OpenGLVertexArray : public VertexArray
{
public:
  OpenGLVertexArray();
  virtual ~OpenGLVertexArray();


  virtual void Bind() const override;
  virtual void UnBind() const override;

  virtual void AddVertexBuffer( const std::shared_ptr<VertexBuffer>& vertexbuffer ) override;
  virtual void SetIndexBuffer( const std::shared_ptr<IndexBuffer>& indexbuffer ) override;
  virtual const std::shared_ptr<IndexBuffer>& GetIndexBuffer() const override
  {
    return mIndexbuffer;
  }

private:
  uint32_t mID;
  uint32_t mVertexBufferAttribIndex = 0;
  std::vector<std::shared_ptr<VertexBuffer>> mVertexBuffers;
  std::shared_ptr<IndexBuffer> mIndexbuffer;
};
}// namespace Cm
#endif