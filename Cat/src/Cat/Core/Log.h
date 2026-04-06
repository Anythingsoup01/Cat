#pragma once

#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#pragma warning(pop)

namespace Cat {

class Log {
public:
  static void Init();

  inline static Ref<spdlog::logger> &GetAPILogger() { return s_APILogger; }
  inline static Ref<spdlog::logger> &GetCLILogger() { return s_CLILogger; }
private:
  inline static Ref<spdlog::logger> s_APILogger;
  inline static Ref<spdlog::logger> s_CLILogger;
};

}

#ifdef C_DEBUG

// Core Log Macros
#define C_API_CRITICAL(...)             ::Cat::Log::GetAPILogger()->critical(__VA_ARGS__)
#define C_API_ERROR(...)                ::Cat::Log::GetAPILogger()->error(__VA_ARGS__)
#define C_API_WARN(...)                 ::Cat::Log::GetAPILogger()->warn(__VA_ARGS__)
#define C_API_INFO(...)                 ::Cat::Log::GetAPILogger()->info(__VA_ARGS__)
#define C_API_TRACE(...)                ::Cat::Log::GetAPILogger()->trace(__VA_ARGS__)

// Client Log Macros
#define C_CLI_CRITICAL(...)             ::Cat::Log::GetCLILogger()->critical(__VA_ARGS__)
#define C_CLI_ERROR(...)                ::Cat::Log::GetCLILogger()->error(__VA_ARGS__)
#define C_CLI_WARN(...)                 ::Cat::Log::GetCLILogger()->warn(__VA_ARGS__)
#define C_CLI_INFO(...)                 ::Cat::Log::GetCLILogger()->info(__VA_ARGS__)
#define C_CLI_TRACE(...)                ::Cat::Log::GetCLILogger()->trace(__VA_ARGS__)
#elif C_RELEASE || C_DIST
// Core Log Macros
#define C_API_CRITICAL(...)
#define C_API_ERROR(...)
#define C_API_WARN(...)
#define C_API_INFO(...)
#define C_API_TRACE(...)

// Client Log Macros
#define C_CLI_CRITICAL(...)             ::Cat::Log::GetCLILogger()->critical(__VA_ARGS__)
#define C_CLI_ERROR(...)                ::Cat::Log::GetCLILogger()->error(__VA_ARGS__)
#define C_CLI_WARN(...)                 ::Cat::Log::GetCLILogger()->warn(__VA_ARGS__)
#define C_CLI_INFO(...)                 ::Cat::Log::GetCLILogger()->info(__VA_ARGS__)
#define C_CLI_TRACE(...)                ::Cat::Log::GetCLILogger()->trace(__VA_ARGS__)

#endif // C_DEBUG
