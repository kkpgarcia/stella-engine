#include <StellaEngine.h>

#include "../imgui/imgui.h"

class ExampleLayer : public StellaEngine::Layer {
public:
	ExampleLayer() : Layer ("Example") {}

	void OnUpdate() override {
		if (StellaEngine::Input::IsKeyPressed(ST_KEY_A)) {
			STELLA_INFO("A key is pressed (poll)!");
		}
	}

	virtual void OnImGuiRender() override {
		ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();
	}

	void OnEvent(StellaEngine::Event& evt) override {
		if (evt.GetEventType() == StellaEngine::EventType::KeyPressed) {
			StellaEngine::KeyPressedEvent& e = (StellaEngine::KeyPressedEvent&)evt;
			if (e.GetKeyCode() == ST_KEY_TAB)
				STELLA_INFO("Tabe key is pressed (event)!");
			STELLA_INFO("{0}", (char)e.GetKeyCode());
		}
	}
};

class Sandbox : public StellaEngine::Application {
public:
	Sandbox() {
		PushLayer(new ExampleLayer());
	}
	~Sandbox() {}
};

StellaEngine::Application* StellaEngine::CreateApplication() {
	return new Sandbox();
}