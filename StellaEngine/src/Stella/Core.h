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

#ifdef STELLA_ENABLE_ASSERTS
	#define STELLA_ASSERT(x, ...) { if(!(x)) { STELLA_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define STELLA_CORE_ASSERT(x, ...) { if(!(x)) { STELLA_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define STELLA_ASSERT(x, ...)
	#define STELLA_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)