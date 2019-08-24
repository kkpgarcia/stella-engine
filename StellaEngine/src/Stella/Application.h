#pragma once

#include "Core.h"
#include "Window.h"
#include "Stella/LayerStack.h"
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

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);
		
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;

	private:
		static Application* s_Instance;
	};


	Application* CreateApplication();
}