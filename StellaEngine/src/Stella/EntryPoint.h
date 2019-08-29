#pragma once

#ifdef STELLA_PLATFORM_WINDOWS

extern StellaEngine::Application* StellaEngine::CreateApplication();

int main(int argc, char** argv) {
	StellaEngine::Log::Init();
	STELLA_CORE_INFO("Initialized Stella Engine.");

	auto app = StellaEngine::CreateApplication();
	app->Run();
	delete app;
	return 0;
}

#endif