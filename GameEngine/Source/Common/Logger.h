#pragma once

#include <string>


class GAMEENGINE_API Logger {

private:
	static Logger* inst;
public:
	static Logger* Instance() { return inst; }

public:
	Logger();
	~Logger();

	static VOID PrintLog(const WCHAR* fmt, ...); // ... means that our inputs can be any amount of these WCHAR*
	static std::wstring LogDirectory();
	static std::wstring LogFile();
};