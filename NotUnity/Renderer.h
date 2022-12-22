#pragma once

#include "NotUnityUtil.h"
#include "Shader.h"
#include "Picture.h"
#include "RendererImplementation.h"

namespace NotUnity
{
	class NOTUNITY_API Renderer
	{
	public:
		static void Init();
		static Renderer* GetRenderer();

		static void Draw(NotUnity::Picture& picture, int x, int y, int z);
		static void Draw(NotUnity::Picture& picture, int x, int y, int z, Shader& shader);

		static void Clear();

	private:
		inline static Renderer* mInstance{ nullptr };

		RendererImplementation* mImplementation;

		Renderer();

		Shader mDefaultShader{ "Assets/Shaders/defaultNotUnityVertex.glsl",
			"Assets/Shaders/defaultNotUnityFragment.glsl" };

		friend class Unit;
	};
}