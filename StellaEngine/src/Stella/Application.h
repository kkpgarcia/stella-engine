#pragma once

#include "Core.h"
#include "Window.h"
#include "Stella/Events/Event.h"

namespace Stella {
	class STELLA_API Application
	{
	public:
		Application();
		virtual ~Application() = default;

		void Run(); 
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	Application* CreateApplication();
}