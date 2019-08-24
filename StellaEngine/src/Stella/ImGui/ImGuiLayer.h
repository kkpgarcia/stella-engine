#pragma once

#include "Stella/Layer.h"

namespace Stella {
	class STELLA_API ImGuiLayer : public Layer {
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
		void OnDetach();
		void OnUpdate();
		void OnEvent(Event& evt);

	private:
		float m_Time = 0.0f;
	};
}