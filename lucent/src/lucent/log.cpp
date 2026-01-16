#include "log.h"
#include <memory>
#include "spdlog/sinks/stdout_color_sinks.h"

// Namespace lucent
namespace lucent
{
	// Definition of static members
	std::shared_ptr<spdlog::logger> log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> log::s_ClientLogger;

	// Initializes the loggers
	void lucent::log::Init()
	{
		// Set the log pattern
		spdlog::set_pattern("%^[%T] %n: %v%$");

		// Create the core logger
		s_CoreLogger = spdlog::stdout_color_mt("LUCENT");
		s_CoreLogger->set_level(spdlog::level::trace);

		// Create the client logger
		s_ClientLogger = spdlog::stdout_color_mt("APP");
		s_ClientLogger->set_level(spdlog::level::trace);
	}
	
}