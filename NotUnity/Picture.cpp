#include "pch.h"
#include "Picture.h"
#include "OpenGLcode/OpenGLPicture.h"

namespace NotUnity
{
	Picture::Picture(const std::string& sourceFile)
	{
#ifdef NOTUNITY_OPENGL
		mImplementation = new OpenGLPicture{ sourceFile };
#else
		#OpenGL_is_the_only_option_right_now
#endif
	}

	Picture::Picture(const std::string&& sourceFile)
	{
#ifdef NOTUNITY_OPENGL
		mImplementation = new OpenGLPicture{ sourceFile };
#else
		#OpenGL_is_the_only_option_right_now
#endif
	}

	int Picture::GetWidth() const
	{
		return mImplementation->GetWidth();
	}

	int Picture::GetHeight() const
	{
		return mImplementation->GetHeight();
	}

	void Picture::Activate()
	{
		mImplementation->Activate();
	}
}