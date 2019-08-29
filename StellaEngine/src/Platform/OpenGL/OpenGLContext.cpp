#include "StellaPH.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include "GL/GL.h"

namespace StellaEngine {
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle) : m_WindowHandle(windowHandle) {
		STELLA_ASSERT(windowHandle, "Window handle is null!");
	}

	void OpenGLContext::Init() {
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		STELLA_ASSERT(status, "Failed to initialize GLAD");

		STELLA_CORE_INFO("OpenGL Info:");
		STELLA_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		STELLA_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		STELLA_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));
	}

	void OpenGLContext::SwapBuffers() {
		glfwSwapBuffers(m_WindowHandle);
	}
}