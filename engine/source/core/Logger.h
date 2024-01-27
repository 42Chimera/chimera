#ifndef CHIMERA_ENGINE_SOURCE_CORE_LOGGER_H
#define CHIMERA_ENGINE_SOURCE_CORE_LOGGER_H

#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
#include "spdlog/sinks/stdout_color_sinks.h"

#include "core/Pch.h"
#include "internal/CmUtil.h"

namespace Cm
{
class CHIMERA_API Logger
{
public:
  static void Init();

  inline static std::shared_ptr<spdlog::logger>& GetCoreLogger()
  {
    return sCoreLogger;
  }
  inline static std::shared_ptr<spdlog::logger>& GetClientLogger()
  {
    return sClientLogger;
  }

private:
  static std::shared_ptr<spdlog::logger> sCoreLogger;
  static std::shared_ptr<spdlog::logger> sClientLogger;
};

// Core Logger Macro
#define CM_CORE_TRACE( ... ) ::Cm::Logger::GetCoreLogger()->trace( __VA_ARGS__ )
#define CM_CORE_INFO( ... ) ::Cm::Logger::GetCoreLogger()->info( __VA_ARGS__ )
#define CM_CORE_WARN( ... ) ::Cm::Logger::GetCoreLogger()->warn( __VA_ARGS__ )
#define CM_CORE_ERROR( ... ) ::Cm::Logger::GetCoreLogger()->error( __VA_ARGS__ )
#define CM_CORE_CRITICAL( ... ) ::Cm::Logger::GetCoreLogger()->critical( __VA_ARGS__ )

// Client Logger Macro
#define CM_CLIENT_TRACE( ... ) ::Cm::Logger::GetClientLogger()->trace( __VA_ARGS__ )
#define CM_CLIENT_INFO( ... ) ::Cm::Logger::GetClientLogger()->info( __VA_ARGS__ )
#define CM_CLIENT_WARN( ... ) ::Cm::Logger::GetClientLogger()->warn( __VA_ARGS__ )
#define CM_CLIENT_ERROR( ... ) ::Cm::Logger::GetClientLogger()->error( __VA_ARGS__ )
#define CM_CLIENT_CRITICAL( ... ) ::Cm::Logger::GetClientLogger()->critical( __VA_ARGS__ )
}// namespace Cm

#endif//CHIMERA_ENGINE_SOURCE_CORE_LOGGER_H