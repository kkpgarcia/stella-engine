#pragma once

#include "Stella/Layer.h"

#include "Stella/Events/ApplicationEvent.h"
#include "Stella/Events/KeyEvent.h"
#include "Stella/Events/MouseEvent.h"

namespace StellaEngine {
	class STELLA_API ImGuiLayer : public Layer {
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};
}