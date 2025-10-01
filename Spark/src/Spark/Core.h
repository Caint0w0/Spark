#pragma once

#ifdef SK_PLATFORM_WINDOWS
	#ifdef SK_BUILD_DLL
		#define SPARK_API __declspec(dllexport)
	#else
		#define SPARK_API __declspec(dllimport)
	#endif
#else
	#error Spark only supports Windows!
#endif 