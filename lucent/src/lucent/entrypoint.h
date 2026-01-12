#pragma once

#include "application.h"
#include "log.h"

#ifdef LCNT_PLATFORM_WINDOWS


extern lucent::application* lucent::createApp();

int main(int argc, char** argv)
{
	lucent::log::Init();
	lucent::log::getCoreLogger()->warn("Lucent Running Successfully");
	lucent::log::getClientLogger()->info("Lucent Running Successfully");

	auto app = lucent::createApp();
	app->run();
	delete app;
}

#endif // 
