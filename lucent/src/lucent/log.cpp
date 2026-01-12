#include "log.h"
#include <memory>
#include "spdlog/sinks/stdout_color_sinks.h"
namespace lucent
{
	std::shared_ptr<spdlog::logger> log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> log::s_ClientLogger;

	void lucent::log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		//------------ LUCENT::INIT_CORE_LOGGER ------------
		s_CoreLogger = spdlog::stdout_color_mt("LUCENT");
		s_CoreLogger->set_level(spdlog::level::trace);

		//------------ APP::INIT_CLIENT_LOGGER ------------
		s_ClientLogger = spdlog::stdout_color_mt("APP");
		s_ClientLogger->set_level(spdlog::level::trace);
	}
	
}