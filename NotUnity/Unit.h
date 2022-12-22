#pragma once

#include "NotUnityUtil.h"
#include "Picture.h"

namespace NotUnity
{
	class NOTUNITY_API Unit
	{
	public:
		Unit(const std::string& picFile, int hp);
		Unit(std::string&& picFile, int hp);

		void SetCoord(int x, int y, int z);
		
		int ChangeX(int xDiff);
		int ChangeY(int yDiff);
		int ChangeZ(int zDiff);

		int GetX() const;
		int GetY() const;
		int GetZ() const;

		int ChangeHP(int hpDiff);
		int GetHP() const;

		bool OverlapsWith(const Unit& other) const;

		void Draw();

	private:
		Picture mPicture;
		int mHP{ 0 };
		int mXcoord{ 0 };
		int mYcoord{ 0 };
		int mZcoord{ 0 };

		friend class Renderer;
	};
}