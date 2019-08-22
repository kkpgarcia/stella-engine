#pragma once

#include "Core.h"
#include "Window.h"
#include "Stella/Events/Event.h"
#include "Stella/Events/ApplicationEvent.h"

namespace Stella {
	class STELLA_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run(); 
		
		void OnEvent(Event& e);

	private:
		bool OnWindowClose(WindowCloseEvent& e);
		
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	Application* CreateApplication();
}