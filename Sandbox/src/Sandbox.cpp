#include <StellaEngine.h>

#include "../imgui/imgui.h"

class ExampleLayer : public Stella::Layer {
public:
	ExampleLayer() : Layer ("Example") {}

	void OnUpdate() override {
		if (Stella::Input::IsKeyPressed(ST_KEY_TAB)) {
			STELLA_TRACE("Tab key is pressed (poll)!");
		}
	}

	virtual void OnImGuiRender() override {
		ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();
	}

	void OnEvent(Stella::Event& evt) override {
		if (evt.GetEventType() == Stella::EventType::KeyPressed) {
			Stella::KeyPressedEvent& e = (Stella::KeyPressedEvent&)evt;
			if (e.GetKeyCode() == ST_KEY_TAB)
				STELLA_TRACE("Tabe key is pressed (event)!");
			STELLA_TRACE("{0}", (char)e.GetKeyCode());
		}
	}
};

class Sandbox : public Stella::Application {
public:
	Sandbox() {
		PushLayer(new ExampleLayer());
	}
	~Sandbox() {}
};

Stella::Application* Stella::CreateApplication() {
	return new Sandbox();
}