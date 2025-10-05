#pragma once
#ifdef SK_PLATFORM_WINDOWS

extern Spark::Application* Spark::CreateApplication();

int main(int argc, char** argv) {

	Spark::Log::Init();
	SK_CORE_WARN("Initialized Logger!");
	
	auto app = Spark::CreateApplication();
	app->Run();
	delete app;
}

#endif