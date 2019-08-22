#pragma once

#ifdef STELLA_PLATFORM_WINDOWS

extern Stella::Application* Stella::CreateApplication();

int main(int argc, char** argv) {
	Stella::Log::Init();
	STELLA_CORE_LOG("Initialized Kitty Engine.");

	auto app = Stella::CreateApplication();
	app->Run();
	delete app;
	return 0;
}

#endif