#pragma once

#ifdef WIN32

#include <windows.h>

#endif

#ifdef BUILD_DLL
	#define GAMEENGINE_API __declspec(dllexport)
#else
	#define GAMEENGINE_API __delcspec(dllimport)
#endif

#define MAX_NAME_STRING 256
#define HInstance() GetModuleHandle(NULL)


#include "Common/Logger.h"
#include "Common/Time.h"
#include "Core/PerGameSettings.h"
