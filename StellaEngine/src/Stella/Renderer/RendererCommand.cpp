#include "StellaPH.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace StellaEngine {
	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;
}