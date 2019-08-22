#include "Application.h"

#include "StellaPH.h"
#include "Input.h"
#include <GLFW/glfw3.h>

namespace StellaEngine {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application* Application::s_Instance = nullptr;

	Application::Application() {
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}

	void Application::OnEvent(Event& e) {
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
	}

	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		
		while(true) {}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e) {
		return true;
	}
}