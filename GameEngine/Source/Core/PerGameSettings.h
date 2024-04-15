#pragma once

class GAMEENGINE_API PerGameSettings {
private:
	static PerGameSettings* inst;

	static PerGameSettings* Instance() { return inst; }

public:
	PerGameSettings();
	~PerGameSettings();

private:
	WCHAR m_GameName[MAX_NAME_STRING];
	WCHAR m_ShortName[MAX_NAME_STRING];
	HICON m_MainIcon;
	WCHAR m_BootTime[MAX_NAME_STRING];
public:
	static WCHAR* GameName() { return inst->m_GameName; }
	static VOID SetGameName(UINT id) { LoadString(HInstance(), id, inst->m_GameName, MAX_NAME_STRING); }

	static WCHAR* ShortName() { return inst->m_GameName; }
	static VOID SetShortName(UINT id) { LoadString(HInstance(), id, inst->m_ShortName, MAX_NAME_STRING); }

	static WCHAR* MainIcon() { return inst->m_GameName; }
	static VOID SetMainIcon(UINT id) { LoadIcon(HInstance(), MAKEINTRESOURCE(id)); }

	static WCHAR* BootTime() { return inst->m_BootTime; }
};

