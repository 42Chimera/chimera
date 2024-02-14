#include "platform/opengl/OpenGLShader.h"
#include "glad/glad.h"

namespace Cm
{
std::unique_ptr<OpenGLShader> OpenGLShader::Create( const std::string& vertexFilePath, const std::string& fragFilePath )
{
  std::unique_ptr<OpenGLShader> shader = std::unique_ptr<OpenGLShader>( new OpenGLShader() );
  if ( !shader->Init( vertexFilePath, fragFilePath ) )
  {
    return nullptr;
  }
  return shader;
}

bool OpenGLShader::Init( const std::string& vertexFilePath, const std::string& fragFilePath )
{
  std::optional<std::string> vertexSrc = LoadFromFile( vertexFilePath );
  std::optional<std::string> fragSrc = LoadFromFile( fragFilePath );
  if ( !vertexSrc.has_value() || !fragSrc.has_value() )
  {
    return false;
  }
  std::string& vertexSource = vertexSrc.value();
  std::string& fragmentSource = fragSrc.value();

  // Create an empty vertex shader handle
  GLuint vertexShader = glCreateShader( GL_VERTEX_SHADER );

  // Send the vertex shader source code to GL
  // Note that std::string's .c_str is NULL character terminated.
  const GLchar* source = (const GLchar*)vertexSource.c_str();
  glShaderSource( vertexShader, 1, &source, 0 );

  // Compile the vertex shader
  glCompileShader( vertexShader );

  GLint isCompiled = 0;
  glGetShaderiv( vertexShader, GL_COMPILE_STATUS, &isCompiled );
  if ( isCompiled == GL_FALSE )
  {
    GLint maxLength = 0;
    glGetShaderiv( vertexShader, GL_INFO_LOG_LENGTH, &maxLength );

    // The maxLength includes the NULL character
    std::vector<GLchar> infoLog( maxLength );
    glGetShaderInfoLog( vertexShader, maxLength, &maxLength, &infoLog[0] );

    // We don't need the shader anymore.
    glDeleteShader( vertexShader );

    // Use the infoLog as you see fit.
    CM_CORE_ERROR( "vertex shader compile error" );
    CM_CORE_ERROR( "   {0}", infoLog.data() );
    // In this simple program, we'll just leave
    return false;
  }

  // Create an empty fragment shader handle
  GLuint fragmentShader = glCreateShader( GL_FRAGMENT_SHADER );

  // Send the fragment shader source code to GL
  // Note that std::string's .c_str is NULL character terminated.
  source = (const GLchar*)fragmentSource.c_str();
  glShaderSource( fragmentShader, 1, &source, 0 );

  // Compile the fragment shader
  glCompileShader( fragmentShader );

  glGetShaderiv( fragmentShader, GL_COMPILE_STATUS, &isCompiled );
  if ( isCompiled == GL_FALSE )
  {
    GLint maxLength = 0;
    glGetShaderiv( fragmentShader, GL_INFO_LOG_LENGTH, &maxLength );

    // The maxLength includes the NULL character
    std::vector<GLchar> infoLog( maxLength );
    glGetShaderInfoLog( fragmentShader, maxLength, &maxLength, &infoLog[0] );

    // We don't need the shader anymore.
    glDeleteShader( fragmentShader );
    // Either of them. Don't leak shaders.
    glDeleteShader( vertexShader );

    // Use the infoLog as you see fit.
    CM_CORE_ERROR( "fragment shader compile error" );
    CM_CORE_ERROR( "   {0}", infoLog.data() );

    // In this simple program, we'll just leave
    return false;
  }

  // Vertex and fragment shaders are successfully compiled.
  // Now time to link them together into a program.
  // Get a program object.
  GLuint program = glCreateProgram();

  // Attach our shaders to our program
  glAttachShader( program, vertexShader );
  glAttachShader( program, fragmentShader );

  // Link our program
  glLinkProgram( program );

  // Note the different functions here: glGetProgram* instead of glGetShader*.
  GLint isLinked = 0;
  glGetProgramiv( program, GL_LINK_STATUS, (int*)&isLinked );
  if ( isLinked == GL_FALSE )
  {
    GLint maxLength = 0;
    glGetProgramiv( program, GL_INFO_LOG_LENGTH, &maxLength );

    // The maxLength includes the NULL character
    std::vector<GLchar> infoLog( maxLength );
    glGetProgramInfoLog( program, maxLength, &maxLength, &infoLog[0] );

    // We don't need the program anymore.
    glDeleteProgram( program );
    // Don't leak shaders either.
    glDeleteShader( vertexShader );
    glDeleteShader( fragmentShader );

    // Use the infoLog as you see fit.
    CM_CORE_ERROR( "shader program compile error" );
    CM_CORE_ERROR( "   {0}", infoLog.data() );

    // In this simple program, we'll just leave
    return false;
  }

  // Always detach shaders after a successful link.
  glDetachShader( program, vertexShader );
  glDetachShader( program, fragmentShader );
  mProgramID = program;
  return true;
}

std::optional<std::string> OpenGLShader::LoadFromFile( const std::string& filePath )
{
  std::string result;

  std::ifstream in( filePath );
  if ( !in.is_open() )
  {
    CM_CORE_ERROR( "file not opened : {0}", filePath );
    return std::nullopt;
  }

  std::stringstream text;
  text << in.rdbuf();
  return text.str();
}

void OpenGLShader::Bind()
{
  glUseProgram( mProgramID );
}

void OpenGLShader::Unbind()
{
  glUseProgram( 0 );
}
}// namespace Cm