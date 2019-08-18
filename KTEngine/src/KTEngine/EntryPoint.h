#pragma once

#ifdef KT_PLATFORM_WINDOWS

#include "Log.h";

extern KTEngine::Application* KTEngine::CreateApplication();

int main(int argc, char** argv) {
	KTEngine::Log::Init();
	KT_CORE_LOG("Initialized Kitty Engine.");

	auto app = KTEngine::CreateApplication();
	app->run();
	delete app;
	return 0;
}

#endif