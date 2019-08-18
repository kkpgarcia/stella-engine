#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace KTEngine {
	Application::Application() {}
	Application::~Application() {}

	void Application::run() {
		WindowResizeEvent e(1280, 720);
		
		while(true) {}
	}
}