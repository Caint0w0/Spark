#pragma once

#ifdef SK_PLATFORM_WINDOWS
#if SK_DYNAMIC_LINK
	#ifdef SK_BUILD_DLL
		#define SPARK_API __declspec(dllexport)
	#else
		#define SPARK_API __declspec(dllimport)
	#endif
#else
#define SPARK_API
#endif
#else
	#error Spark only supports Windows!
#endif 

#ifdef SK_ENABLE_ASSERTS
	#define SK_ASSERT(x,...) { if(!(x)){ SK_ERROR("Assertion failed: {0}",__VA_ARGS__);__debugbreak(); } }
	#define SK_CORE_ASSERT(x,...) { if(!(x)){ SK_CORE_ERROR("Assertion failed: {0}",__VA_ARGS__);__debugbreak(); } }
#else
	#define SK_ASSERT(x,...)
	#define SK_CORE_ASSERT(x,...)
#endif

#define BIT(x) (1<<x)

#define SK_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)