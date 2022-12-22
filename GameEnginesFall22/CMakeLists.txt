set(SOURCE_FILES
	Fall22.cpp
)

add_executable(GameEnginesFall22 ${SOURCE_FILES})

include_directories(../NotUnity)

target_link_libraries(GameEnginesFall22 NotUnity)

file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/GameEnginesFall22)
file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Debug)
file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Release)