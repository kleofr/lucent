#pragma once

// Platform detection
#ifdef LCNT_PLATFORM_WINDOWS

	// DLL support
	#ifdef LCNT_BUILD_DLL

		// Exporting symbols
		#define LCNT_API __declspec(dllexport)
	#else
		#define LCNT_API __declspec(dllimport)
	#endif // LCNT_BUILD_DLL
#else
	// Unsupported platform
	#error Lucent Supports only Windows!

#endif // LCNT_PLATFORM_WINDOWS
