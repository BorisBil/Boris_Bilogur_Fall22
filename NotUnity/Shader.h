#pragma once

#include "NotUnityUtil.h"
#include "pch.h"
#include "ShaderImplementation.h"

namespace NotUnity
{
	class NOTUNITY_API Shader
	{
	public:
		Shader(const std::string& vertexFile, const std::string& fragmentFile);
		Shader(std::string&& vertexFile, std::string&& fragmentFile);

		void Activate();

		void ProvideFloatValues(const std::string& valueName, const std::vector<float>& vals);
		void ProvideFloatValues(std::string&& valueName, std::vector<float>&& vals);

	private:
		ShaderImplementation* mImplementation{ nullptr };
	};
}