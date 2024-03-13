#include <glad/glad.h>
#include "platform/opengl/OpenGLVertexBuffer.h"

namespace Cm
{
OpenGLVertexBuffer::OpenGLVertexBuffer( float* vertices, uint32_t size )
{
  glGenBuffers( 1, &mID );
  glBindBuffer( GL_ARRAY_BUFFER, mID );
  glBufferData( GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW );
}

OpenGLVertexBuffer::~OpenGLVertexBuffer()
{
  glDeleteBuffers( 1, &mID );
}

void OpenGLVertexBuffer::Bind() const
{
  glBindBuffer( GL_ARRAY_BUFFER, mID );
}

void OpenGLVertexBuffer::UnBind() const
{
  glBindBuffer( GL_ARRAY_BUFFER, 0 );
}

void OpenGLVertexBuffer::SetData( const void* data, uint32_t size ) const
{
  Bind();
  // 기존에 이미 GPU에 존재하는 buffer data를 업데이트 함
  // 다시 만드는 것 보다 성능 이점 있음
  glBufferSubData( GL_ARRAY_BUFFER, 0, size, data );
}

}// namespace Cm