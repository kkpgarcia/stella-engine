#pragma once

#include "Core.h"
#include "Window.h"
#include "StellaEngine/Events/Event.h"
#include "StellaEngine/Events/ApplicationEvent.h"

namespace StellaEngine {
	class Application
	{
	public:
		Application();
		virtual ~Application() = default;

		void Run(); 

		void OnEvent(Event& e);

		inline Window& GetWindow() { return *m_Window; }
		inline static Application& Get() { return *s_Instance; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;

		static Application* s_Instance;
	};

	Application* CreateApplication();
}

