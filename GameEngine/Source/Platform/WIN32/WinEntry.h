#include "GameEngine.h"
#include "IApplication.h"

extern IApplication* EntryApplication();


INT CALLBACK WinMain(HINSTANCE, HINSTANCE, LPSTR, INT) {

	auto EntryApp = EntryApplication();

	PerGameSettings GameSettings;

	EntryApp->SetupPerGameSettings();
	EntryApp->Initialize();

	Logger logger;

	MSG msg{ 0 };

	while (msg.message != WM_QUIT) {
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else {
			EntryApp->Update();
		}
	}



	return 0;
}