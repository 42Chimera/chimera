#include "platform/opengl/OpenGLVertexArray.h"
#include <glad/glad.h>

namespace Cm
{
OpenGLVertexArray::OpenGLVertexArray()
{
  glGenVertexArrays( 1, &mID );
}

OpenGLVertexArray::~OpenGLVertexArray()
{
  glDeleteVertexArrays( 1, &mID );
}

void OpenGLVertexArray::Bind() const
{
  glBindVertexArray( mID );
}

void OpenGLVertexArray::UnBind() const
{
  glBindVertexArray( 0 );
}

void OpenGLVertexArray::AddVertexBuffer( const std::shared_ptr<VertexBuffer>& vertexbuffer )
{
  //vao bind
  Bind();
  //vertexbuffer bind
  vertexbuffer->Bind();

  const BufferLayout& layout = vertexbuffer->GetLayout();
  //set vertexattribute
  for ( const BufferElement& element : layout )
  {
    glEnableVertexAttribArray( mVertexBufferAttribIndex );
    glVertexAttribPointer( mVertexBufferAttribIndex, element.GetTypeCount(), GL_FLOAT, element.GetIsNormalized() ? GL_TRUE : GL_FALSE, layout.GetStride(), (const void*)element.GetOffset() );
    mVertexBufferAttribIndex++;
  }
  mVertexBuffers.push_back( vertexbuffer );
}

void OpenGLVertexArray::SetIndexBuffer( const std::shared_ptr<IndexBuffer>& indexbuffer )
{
  Bind();
  indexbuffer->Bind();
  mIndexbuffer = indexbuffer;
}
}// namespace Cm
