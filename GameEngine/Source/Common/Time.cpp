#include "GameEngine.h"
#include <sstream>
#include <iomanip>

std::wstring GAMEENGINE_API Time::GetTime(BOOL striped)
{
	time_t now =	time(nullptr);
	tm ltm;
	localtime_s(&ltm, &now);
	std::wstringstream wss;
	wss << std::put_time(&ltm, L"%T");

	std::wstring timeString = wss.str();

	if (striped) {
		std::wstring chars = L":";
		for (WCHAR c : chars) {
			timeString.erase(std::remove(timeString.begin(), timeString.end(), c), timeString.end();
		}
	}

	return timeString;
} 

std::wstring GAMEENGINE_API Time::GetDate(BOOL striped)
{
	time_t now = time(0);
	tm ltm;
	localtime_s(&ltm, &now);
	std::wstringstream wss;
	wss << std::put_time(&ltm, L"/%d/%m/%y");

	std::wstring timeString = wss.str();

	if (striped) {
		std::wstring chars = L":";
		for (WCHAR c : chars) {
			timeString.erase(std::remove(timeString.begin(), timeString.end(), c), timeString.end();
		}
	}

	return timeString;
}

std::wstring GAMEENGINE_API Time::GetDateTimeString(BOOL striped)
{
	std::wstring timeString = GetDate(striped) + L" " + GetTime(striped);

	if (striped) {
		std::wstring chars = L" ";
		for (WCHAR c : chars) {
			timeString.erase(std::remove(timeString.begin(), timeString.end(), c), timeString.end();

		}
	}
}