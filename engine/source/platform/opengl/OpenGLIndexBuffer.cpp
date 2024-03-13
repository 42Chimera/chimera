#include <glad/glad.h>
#include "platform/opengl/OpenGLIndexBuffer.h"

namespace Cm
{
OpenGLIndexBuffer::OpenGLIndexBuffer( float* indices, uint32_t size )
{
  glGenBuffers( 1, &mID );
  glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, mID );
  glBufferData( GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW );
}

OpenGLIndexBuffer::~OpenGLIndexBuffer()
{
  glDeleteBuffers( 1, &mID );
}

void OpenGLIndexBuffer::Bind() const
{
  glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, mID );
}

void OpenGLIndexBuffer::UnBind() const
{
  glBindBuffer( GL_ELEMENT_ARRAY_BARRIER_BIT, 0 );
}

void OpenGLIndexBuffer::SetData( const void* data, uint32_t size ) const
{
  Bind();
  glBufferSubData( GL_ELEMENT_ARRAY_BUFFER, 0, size, data );
}
}// namespace Cm