#pragma once

#include "pch.h"
#include "NotUnityWindow.h"
#include "GLFWcode/GLFWimplementation.h"

namespace NotUnity
{
	void NotUnityWindow::Init()
	{
		if (mInstance == nullptr)
		{
			mInstance = new NotUnityWindow;
		#ifdef NOTUNITY_WINDOWS
			mInstance->mImplementation = new GLFWimplementation;
		#elif defined NOTUNITY_MAC
			mInstance->mImplementation = new GLFWimplementation;
		#else
			mInstance->mImplementation = new GLFWimplementation;
		#endif
		}
			

	}

	NotUnityWindow* NotUnityWindow::GetWindow()
	{
		return mInstance;
	}

	void NotUnityWindow::Create(int width, int height, const std::string& windowName)
	{
		mImplementation->Create(width, height, windowName);

		mWidth = width;
		mHeight = height;
	}

	void NotUnityWindow::SwapBuffers()
	{
		mImplementation->SwapBuffers();
	}
	
	int NotUnityWindow::GetWidth() const
	{
		return mWidth;
	}
	
	int NotUnityWindow::GetHeight() const
	{
		return mHeight;
	}
	
	void NotUnityWindow::SetKeyPressedCallback(const std::function<void(const KeyPressedEvent&)>& keyPressedCallback)
	{
		mImplementation->SetKeyPressedCallback(keyPressedCallback);
	}
	
	void NotUnityWindow::SetKeyReleasedCallback(const std::function<void(const KeyReleasedEvent&)>& keyReleasedCallback)
	{
		mImplementation->SetKeyReleasedCallback(keyReleasedCallback);
	}
}