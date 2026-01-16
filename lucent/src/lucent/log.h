#pragma once

#include "core.h"
#include "spdlog/spdlog.h"

namespace lucent
{
	class LCNT_API log
	{
	public:
		// Initializes the loggers
		static void Init();

		// Getters
		inline static std::shared_ptr<spdlog::logger>& getCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& getClientLogger() { return s_ClientLogger; }


	private:
		// Loggers
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}
// Core log macros
#define LCNT_CORE_TRACE(...)    ::lucent::log::getCoreLogger()->trace(__VA_ARGS__)
#define LCNT_CORE_INFO(...)     ::lucent::log::getCoreLogger()->info(__VA_ARGS__)
#define LCNT_CORE_WARN(...)     ::lucent::log::getCoreLogger()->warn(__VA_ARGS__)
#define LCNT_CORE_ERROR(...)    ::lucent::log::getCoreLogger()->error(__VA_ARGS__)

// Client log macros
#define LCNT_CLIENT_TRACE(...)     ::lucent::log::getClientLogger()->trace(__VA_ARGS__)
#define LCNT_CLIENT_INFO(...)      ::lucent::log::getClientLogger()->info(__VA_ARGS__)
#define LCNT_CLIENT_WARN(...)      ::lucent::log::getClientLogger()->warn(__VA_ARGS__)
#define LCNT_CLIENT_ERROR(...)     ::lucent::log::getClientLogger()->error(__VA_ARGS__)


