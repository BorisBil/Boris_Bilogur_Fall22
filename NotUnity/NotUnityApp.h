#pragma once

#include "pch.h"
#include "NotUnityUtil.h"

constexpr int FRAMES_PER_SECOND = 60;

namespace NotUnity
{
	class NOTUNITY_API NotUnityApp
	{
	public:
		NotUnityApp();
		virtual void OnUpdate();
		void Run();

	private:
		std::chrono::milliseconds mFrameDuration{ 1000 / FRAMES_PER_SECOND };
		std::chrono::steady_clock::time_point mNextFrameTime;
	};
}