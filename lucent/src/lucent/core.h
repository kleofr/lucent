#pragma once

#ifdef LCNT_PLATFORM_WINDOWS
	#ifdef LCNT_BUILD_DLL
		#define LCNT_API __declspec(dllexport)
	#else
		#define LCNT_API __declspec(dllimport)
	#endif // LCNT_BUILD_DLL
#else
	#error Lucent Supports only Windows!
#endif // LCNT_PLATFORM_WINDOWS
