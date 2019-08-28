#include "StellaPH.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Stella {
	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;
}