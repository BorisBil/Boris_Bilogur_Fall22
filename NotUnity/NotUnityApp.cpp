#include "pch.h"
#include "NotUnityApp.h"
#include "NotUnityUtil.h"
#include "NotUnityWindow.h"
#include "glad/glad.h"
#include "stb_image.h"
#include "Picture.h"
#include "Renderer.h"
#include "Event.h"
#include "Keys.h"

namespace NotUnity
{
	NotUnityApp::NotUnityApp()
	{
		NotUnityWindow::Init();
		NotUnityWindow::GetWindow()->Create(1000, 800, "TestWindow");

		Renderer::Init();
	}

	void NotUnityApp::OnUpdate()
	{

	}

	void NotUnityApp::Run()
	{
		NOTUNITY_LOG("NotUnity Running...");

		mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;
		
		while (true)
		{
			Renderer::Clear();

			OnUpdate();

			std::this_thread::sleep_until(mNextFrameTime);

			NotUnityWindow::GetWindow()->SwapBuffers();

			mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;
		}
	}
}