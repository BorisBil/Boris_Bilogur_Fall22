#pragma once

#include "NotUnity.h"
#include "Unit.h"

class Fall22Game : public NotUnity::NotUnityApp 
{
	public:
		Fall22Game();

		virtual void OnUpdate() override;

	private:
		NotUnity::Unit m_Character{ "Assets/Textures/character.png", 1 };
};