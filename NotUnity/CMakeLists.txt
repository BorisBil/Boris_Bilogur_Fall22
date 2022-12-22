set(SOURCE_FILES
	Event.cpp
	OpenGLcode/OpenGLPicture.cpp
	OpenGLcode/OpenGLShader.cpp
	OpenGLcode/OpenGLRenderer.cpp
	Picture.cpp
	Shader.cpp
	Renderer.cpp
	Unit.cpp
	NotUnityApp.cpp
	NotUnityWindow.cpp
	GLFWcode/GLFWimplementation.cpp
   )

set(HEADER_FILES
	Event.h
	Keys.h
	OpenGLcode/OpenGLPicture.h
	OpenGLcode/OpenGLShader.h
	OpenGLcode/OpenGLRenderer.h
	Picture.h
	Shader.h
	Renderer.h
	PictureImplementation.h
	ShaderImplementation.h
	RendererImplementation.h
	Unit.h
	NotUnity.h
	NotUnityApp.h
	NotUnityUtil.h
	NotUnityWindow.h
	WindowImplementation.h
	GLFWcode/GLFWimplementation.h
   )

add_library(NotUnity SHARED ${SOURCE_FILES} ${HEADER_FILES})

add_definitions(-DNOTUNITY_LIB)

target_precompile_headers(NotUnity PRIVATE pch.h)

include_directories(../glfw/include/)
include_directories(../NotUnity)
include_directories(../glad/include/)
include_directories(../stbi)

target_link_libraries(NotUnity glfw glad stbi)