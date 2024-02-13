#ifndef CHIMERA_ENGINE_SOURCE_RENDER_BUFFER_H
#define CHIMERA_ENGINE_SOURCE_RENDER_BUFFER_H

#include "core/Pch.h"

namespace Cm
{
enum class ShaderDataType
{
  None = 0,
  Float,
  Float2,
  Float3,
  Float4,
  Mat3,
  Mat4
};

static uint32_t ShaderDataTypeSize( ShaderDataType type )
{
  switch ( type )
  {
    case ShaderDataType::Float:
      return 4;
    case ShaderDataType::Float2:
      return 4 * 2;
    case ShaderDataType::Float3:
      return 4 * 3;
    case ShaderDataType::Float4:
      return 4 * 4;
    case ShaderDataType::Mat3:
      return 4 * 3 * 3;
    case ShaderDataType::Mat4:
      return 4 * 4 * 4;
  }
  CM_ASSERT_DEV( "박지윤", false, "not supported shader data type!" );
  return 0;
}

class BufferElement
{
public:
  BufferElement( const std::string& name, ShaderDataType type, bool isNormalized )
      : mName( name )
      , mType( type )
      , mSize( ShaderDataTypeSize( type ) )
      , mOffset( 0 )
      , mIsNormalized( isNormalized )
  {
  }
  uint32_t GetTypeCount() const
  {
    switch ( mType )
    {
      case ShaderDataType::Float:
        return 1;
      case ShaderDataType::Float2:
        return 2;
      case ShaderDataType::Float3:
        return 3;
      case ShaderDataType::Float4:
        return 4;
      case ShaderDataType::Mat3:
        return 3;
      case ShaderDataType::Mat4:
        return 4;
    }
    CM_ASSERT_DEV( "박지윤", false, "not supported shader data type!" );
    return 0;
  }
  const std::string& GetName() const
  {
    return mName;
  }
  ShaderDataType GetType() const
  {
    return mType;
  }
  uint32_t GetSize() const
  {
    return mSize;
  }
  size_t GetOffset() const
  {
    return mOffset;
  }
  bool GetIsNormalized() const
  {
    return mIsNormalized;
  }

  void SetOffset( size_t offset )
  {
    mOffset = offset;
  }

private:
  std::string mName;
  ShaderDataType mType;
  uint32_t mSize;
  size_t mOffset;
  bool mIsNormalized;
};

class BufferLayout
{
public:
  BufferLayout( std::initializer_list<BufferElement> elements )
      : mElements( elements )
  {
    SetOffsetAndStride();
  }

private:
  void SetOffsetAndStride()
  {
    size_t offset = 0;
    mStride = 0;
    for ( BufferElement& element : mElements )
    {
      element.SetOffset( offset );
      offset = element.GetSize();
      mStride += element.GetSize();
    }
  }

private:
  std::vector<BufferElement> mElements;
  uint32_t mStride = 0;
};
}// namespace Cm
#endif