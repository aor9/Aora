#pragma once

#ifdef AO_PLATFORM_WINDOWS
	#ifdef AO_BUILD_DLL
		#define AORA_API __declspec(dllexport)
	#else
		#define AORA_API __declspec(dllimport)
	#endif
#else
	#error Aora only supports Windows!
#endif

#define BIT(x) (1 << x)