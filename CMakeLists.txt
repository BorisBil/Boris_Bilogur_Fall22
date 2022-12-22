cmake_minimum_required(VERSION 3.20)

project(final_game)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

if(WIN32)
	add_definitions(-DNOTUNITY_WINDOWS)
elseif(APPLE)
	add_definitions(-DNOTUNITY_MAC)
else()
	add_definitions(-DNOTUNITY_LINUX)
endif()

add_definitions(-DNOTUNITY_DEBUG)
add_definitions(-DNOTUNITY_OPENGL)

add_subdirectory(GameEnginesFall22)
add_subdirectory(NotUnity)
add_subdirectory(glfw)
add_subdirectory(glad)
add_subdirectory(stbi)

set(VS_STARTUP_PROJECT GameEnginesFall22)

file(COPY GameEnginesFall22/Assets DESTINATION ${PROJECT_BINARY_DIR}/GameEnginesFall22)
file(COPY GameEnginesFall22/Assets DESTINATION ${PROJECT_BINARY_DIR}/Debug)
file(COPY GameEnginesFall22/Assets DESTINATION ${PROJECT_BINARY_DIR}/Release)