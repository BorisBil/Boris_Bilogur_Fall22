#pragma once

#define START_NOTUNITY_GAME(GameClass) \
	int main()\
	{ \
		GameClass __unity__game;\
		__unity__game.Run();\
		return 0;\
	}

#ifdef NOTUNITY_WINDOWS
	#ifdef NOTUNITY_LIB
		#define	NOTUNITY_API __declspec(dllexport)
	#else
		#define NOTUNITY_API __declspec(dllimport)
	#endif
#else
	#define NOTUNITY_API
#endif

#ifdef NOTUNITY_DEBUG
	#define NOTUNITY_LOG(x)  std::cout<<x<<std::endl;
#else
	#define NOTUNITY_LOG(x)
#endif