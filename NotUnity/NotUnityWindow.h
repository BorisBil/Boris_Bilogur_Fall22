#pragma once

#include "pch.h"
#include "NotUnityUtil.h"
#include "WindowImplementation.h"

namespace NotUnity
{
	class NOTUNITY_API NotUnityWindow
	{
	public:
		static void Init();
		static NotUnityWindow* GetWindow();
		
		void Create(int width, int height, const std::string& windowName);
		void SwapBuffers();

		int GetWidth() const;
		int GetHeight() const;

		void SetKeyPressedCallback(const std::function<void(const KeyPressedEvent&)>& keyPressedCallback);
		void SetKeyReleasedCallback(const std::function<void(const KeyReleasedEvent&)>& keyReleasedCallback);

	private:
		inline static NotUnityWindow* mInstance{ nullptr };

		WindowImplementation* mImplementation{ nullptr };

		int mWidth{ 0 };
		int mHeight{ 0 };
	};
}
