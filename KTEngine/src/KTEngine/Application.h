#pragma once

#include "Core.h"
#include "Window.h"
#include "KTEngine/Events/Event.h"
#include "KTEngine/Events/ApplicationEvent.h"

namespace KTEngine {
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

