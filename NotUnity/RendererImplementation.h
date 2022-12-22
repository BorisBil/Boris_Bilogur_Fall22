#pragma once

#include "Shader.h"
#include "Picture.h"

namespace NotUnity
{
	class RendererImplementation
	{
	public:
		virtual void Draw(Picture& picture, int x, int y, int z, Shader& shader) = 0;
		virtual void Clear() = 0;
	};
}