#pragma once


#ifdef LCNT_PLATFORM_WINDOWS
#include "application.h"

extern lucent::application* lucent::createApp();

int main(int argc, char** argv)
{
	printf("Lucent Engine");
	auto app = lucent::createApp();
	app->run();
	delete app;
}

#endif // 
