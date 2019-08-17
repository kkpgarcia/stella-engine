#pragma once

#ifdef KT_PLATFORM_WINDOWS

extern KTEngine::Application* KTEngine::CreateApplication();

int main(int argc, char** argv) {
	auto app = KTEngine::CreateApplication();
	app->run();
	delete app;
	return 0;
}

#endif