#pragma once

#ifdef STELLA_PLATFORM_WINDOWS
#ifdef STELLA_BUILD_DLL
		#define STELLA_API __declspec(dllexport)
	#else
		#define STELLA_API __declspec(dllimport)
	#endif
#else
	#error KT ONLY SUPPORTS WINDOWS 
#endif

#define BIT(x) (1 << x)