#pragma once

#define ENTRYAPP(x) IApplication* EntryApplication() { return new x; }

class GAMEENGINE_API IApplication {


public:
	IApplication();


	virtual ~IApplication() = default;


public:

	virtual VOID SetupPerGameSettings() = 0;


	// Initialize application
	virtual VOID Initialize() = 0;

	// Game loop
	virtual VOID Update() = 0;

};

IApplication* EntryApplication();