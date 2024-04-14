#include "GameEngine.h"
#include <fstream>
#include <ShlObj.h>

Logger* Logger::inst = nullptr;

Logger::Logger()
{
	inst = this; // The first time it is created, it will make this into the singleton or static class
}

Logger::~Logger()
{
}

VOID Logger::PrintLog(const WCHAR* fmt, ...)
{
	WCHAR buf[4096];
	va_list args;
	va_start(args, fmt);
	vswprintf_s(buf, fmt,args);
	va_end(args);

	//MessageBox(0, buf, 0, 0);

	OutputDebugString(buf);

	std::wfstream outFile;

	outFile.open(std::wstring(LogDirectory() + L"/" + LogFile()), std::ios_base::app);

	if (outFile.is_open()) {
		std::wstring s = buf;
		outFile << L"[" << Time::GetDateTimeString() << L"]" << s;
		outFile.close();
		OutputDebugString(s.c_str());
	}
	else {
		MessageBox(NULL, L"Unable to open log file...", L"Log Error", MB_OK);
	}
}

std::wstring Logger::LogDirectory()
{
	WCHAR Path[1024];
	WCHAR* AppDataLocal;
	SHGetKnownFolderPath(FOLDERID_RoamingAppData, 0, nullptr, &AppDataLocal);
	wcscpy_s(Path, AppDataLocal);
	wcscat_s(Path, L"\\");
	wcscat_s(Path, PerGameSettings::GameName());
	CreateDirectory(Path, NULL);
	wcscat_s(Path, L"\\Log");
	CreateDirectory(Path, NULL);
	return Path;
}

std::wstring Logger::LogFile()
{
	WCHAR File[1024];
	wcscpy_s(File, PerGameSettings::GameName());
	wcscat_s(File, PerGameSettings::BootTime());
	wcscat_s(File, L".log");
	return std::wstring();
}
