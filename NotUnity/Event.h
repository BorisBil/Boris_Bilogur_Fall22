#pragma once

#include "NotUnityUtil.h"

namespace NotUnity
{
	class NOTUNITY_API KeyPressedEvent
	{
	public:
		KeyPressedEvent(int codeOfKey);
		KeyPressedEvent() = delete;

		int GetKeyCode() const;

	private:
		int mKeyCode;
	};

	class NOTUNITY_API KeyReleasedEvent
	{
	public:
		KeyReleasedEvent(int codeOfKey);
		KeyReleasedEvent() = delete;

		int GetKeyCode() const;

	private:
		int mKeyCode;
	};
}
