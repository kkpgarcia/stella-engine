#pragma once

#include "Core.h"
#include "Window.h"
#include "Stella/LayerStack.h"
#include "Stella/Events/Event.h"
#include "Stella/Events/ApplicationEvent.h"

#include "Stella/ImGui/ImGuiLayer.h"

#include "Stella/Renderer/Shader.h"
#include "Stella/Renderer/Buffer.h"
#include "Stella/Renderer/VertexArray.h"

#include "Stella/Renderer/OrthographicCamera.h"

namespace StellaEngine {
	class STELLA_API Application
	{
	public:
		Application();
		virtual ~Application() = default;

		void Run(); 
		
		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);
		
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

		std::shared_ptr<Shader> m_Shader;
		std::shared_ptr<VertexArray> m_VertexArray;

		std::shared_ptr<Shader> m_BlueShader;
		std::shared_ptr<VertexArray> m_SquareVA;

		OrthographicCamera m_Camera;
	private:
		static Application* s_Instance;
	};


	Application* CreateApplication();
}