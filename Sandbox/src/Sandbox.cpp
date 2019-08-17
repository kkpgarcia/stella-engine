#include <KTEngine.h>

class Sandbox : public KTEngine::Application {
public:
	Sandbox() {}
	~Sandbox() {}
};

KTEngine::Application* KTEngine::CreateApplication() {
	return new Sandbox();
}