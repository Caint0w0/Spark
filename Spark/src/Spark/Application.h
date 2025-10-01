#pragma once

#include "Core.h"

namespace Spark {
	class SPARK_API Application
	{
	public:
		Application();
		virtual ~Application();

		virtual void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}
