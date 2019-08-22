#include <StellaEngine.h>

class Sandbox : public StellaEngine::Application {
public:
	Sandbox() {}
	~Sandbox() {}
};

StellaEngine::Application* StellaEngine::CreateApplication() {
	return new Sandbox();
}