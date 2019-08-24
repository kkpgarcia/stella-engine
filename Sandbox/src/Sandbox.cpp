#include <StellaEngine.h>

class ExampleLayer : public Stella::Layer {
public:
	ExampleLayer() : Layer ("Example") {}

	void OnUpdate() override {
		STELLA_DEBUG("ExampleLayer::Update()");
	}

	void OnEvent(Stella::Event& evt) override {
		STELLA_TRACE("{0}", evt);
	}
};

class Sandbox : public Stella::Application {
public:
	Sandbox() {
		PushLayer(new ExampleLayer());
		PushOverlay(new Stella::ImGuiLayer());
	}
	~Sandbox() {}
};

Stella::Application* Stella::CreateApplication() {
	return new Sandbox();
}