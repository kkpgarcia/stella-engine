#pragma once

#ifdef KT_PLATFORM_WINDOWS

#include "Log.h";

extern KTEngine::Application* KTEngine::CreateApplication();

int main(int argc, char** argv) {
	KTEngine::Log::Init();
	KT_CORE_WARNING("Initialized Log");
	KT_CORE_LOG("INFOOOO");
	KT_CORE_ERROR("SAMPLE ERROR");

	auto app = KTEngine::CreateApplication();
	app->run();
	delete app;
	return 0;
}

#endif