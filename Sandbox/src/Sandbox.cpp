#include <StellaEngine.h>

class Sandbox : public Stella::Application {
public:
	Sandbox() {}
	~Sandbox() {}
};

Stella::Application* Stella::CreateApplication() {
	return new Sandbox();
}