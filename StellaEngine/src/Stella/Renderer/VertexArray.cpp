#include "StellaPH.h"
#include "VertexArray.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace StellaEngine {
	VertexArray* VertexArray::Create() {
		switch (Renderer::GetAPI()) {
			case RendererAPI::API::None:
				STELLA_CORE_ASSERT(false, "RendererAPI::None is currently not supported!");
			case RendererAPI::API::OpenGL:
				return new OpenGLVertexArray();
		}

		STELLA_CORE_ASSERT(false, "Unkown Renderer API");
		return nullptr;
	}
}