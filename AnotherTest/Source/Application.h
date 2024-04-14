#pragma once

#include "Platform/WIN32/IApplication.h"

class Application : public IApplication {

	
public:
	Application();


	~Application();


public :

	VOID SetupPerGameSettings();

	// Initialize application
	VOID Initialize();

	// Game loop
	VOID Update();

};