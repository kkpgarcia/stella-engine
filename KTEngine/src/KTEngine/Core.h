#pragma once

#ifdef KT_PLATFORM_WINDOWS
#ifdef KT_BUILD_DLL
		#define KT_API __declspec(dllexport)
	#else
		#define KT_API __declspec(dllimport)
	#endif
#else
	#error KT ONLY SUPPORTS WINDOWS 
#endif