#pragma once

#include "Core.h"

namespace KTEngine {
	class KT_API Application
	{
	public:
		Application();
		~Application();

		virtual void run();
	};

	Application* CreateApplication();
}

