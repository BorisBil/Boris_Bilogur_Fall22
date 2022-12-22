#pragma once

#include "pch.h"
#include "NotUnityUtil.h"
#include "PictureImplementation.h"

namespace NotUnity
{
	class NOTUNITY_API Picture
	{
	public:
		Picture(const std::string& sourceFile);
		Picture(const std::string&& sourceFile);
		
		int GetHeight() const;
		int GetWidth() const;

		void Activate();

	private:
		PictureImplementation* mImplementation{ nullptr };
	};
}