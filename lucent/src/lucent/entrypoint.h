#pragma once

#include "application.h"
#include "log.h"

// Platform detection
#ifdef LCNT_PLATFORM_WINDOWS

// Entry point for Windows
extern lucent::application* lucent::createApp();

// Main function
int main(int argc, char** argv)
{
	// Initialize loggers
	lucent::log::Init();

	// Test loggers
	LCNT_CORE_INFO("Core logger working");
	LCNT_CLIENT_ERROR("Client logger working");

	// Create application
	auto app = lucent::createApp();
	app->run();
	delete app;
}

#endif // 
