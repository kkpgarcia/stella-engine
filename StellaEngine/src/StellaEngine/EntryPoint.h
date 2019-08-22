#pragma once

#ifdef STELLA_PLATFORM_WINDOWS

#include "Log.h";

extern StellaEngine::Application* StellaEngine::CreateApplication();

int main(int argc, char** argv) {
	StellaEngine::Log::Init();
	KT_CORE_LOG("Initialized Kitty Engine.");

	auto app = StellaEngine::CreateApplication();
	app->run();
	delete app;
	return 0;
}

#endif