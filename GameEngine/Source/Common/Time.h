#pragma once
#include <string>

namespace Time {

	//Get current time in string format
	std::wstring GAMEENGINE_API GetTime(BOOL striped = FALSE);
	// get date in string format
	std::wstring GAMEENGINE_API GetDate(BOOL striped = FALSE);
	//get date and time in string format
	std::wstring GAMEENGINE_API GetDateTimeString(BOOL striped = FALSE);
}