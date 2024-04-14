#include "GameEngine.h"

PerGameSettings* PerGameSettings::inst;

PerGameSettings::PerGameSettings()
{
	inst = this;

	wcscpy_s(inst->m_GameName, L"undef");
	wcscpy_s(inst->m_ShortName, L"undef");
	wcscpy_s(inst->m_BootTime, Time::GetDateTimeString(TRUE).c_str());
}

PerGameSettings::~PerGameSettings()
{
}
