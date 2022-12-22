#pragma once

#include "../RendererImplementation.h"

namespace NotUnity
{
	class OpenGLRenderer : public RendererImplementation
	{
	public:
		OpenGLRenderer();
		void Draw(Picture& picture, int x, int y, int z, Shader& shader) override;
		virtual void Clear() override;
	};
}