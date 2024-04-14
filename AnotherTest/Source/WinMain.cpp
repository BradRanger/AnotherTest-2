#include "pch.h"


#pragma region GlobalVariables
WCHAR WindowClass[MAX_NAME_STRING];
WCHAR WindowTitle[MAX_NAME_STRING];

INT	WindowWidth;
INT WindowHeight;


HICON hIcon;
#pragma endregion


static LRESULT CALLBACK WindowProcess(HWND hWnd, UINT message, WPARAM wparam, LPARAM lparam) {

	switch (message) {
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}



	return DefWindowProc(hWnd, message, wparam, lparam);
}

#pragma region Pre-Declarations

VOID InitializeVariables();
// Create Window Class
VOID CreateWindowClass();
// Create and display our window
VOID InitializeWIndow();
// Listen for message events
VOID MessageLoop();

#pragma endregion

//INT CALLBACK WinMain(HINSTANCE, HINSTANCE, LPSTR, INT) {
//
//	InitializeVariables();
//	CreateWindowClass();
//	InitializeWIndow();
//	MessageLoop();
//
//
//
//
//
//	return 0;
//}




// Initialize global variables
VOID InitializeVariables() {
	LoadString(HInstance(), IDS_PERGAMENAME, WindowTitle, MAX_NAME_STRING);

	if (!LoadString(HInstance(), IDS_PERGAMENAME, WindowTitle, MAX_NAME_STRING)) {
		MessageBox(0, L"Failed to load window title.", 0, 0);
		exit(EXIT_FAILURE);
	}

	LoadString(HInstance(), IDS_WINDOWCLASS, WindowClass, MAX_NAME_STRING);

	if (!LoadString(HInstance(), IDS_WINDOWCLASS, WindowClass, MAX_NAME_STRING)) {
		MessageBox(0, L"Failed to load window class name.", 0, 0);
		exit(EXIT_FAILURE);
	}
	WindowWidth = 1366;
	WindowHeight = 768;
	hIcon = LoadIcon(HInstance(), MAKEINTRESOURCE(IDI_MAINICON));


}

VOID CreateWindowClass(){
	WNDCLASSEX wcex = {0};


	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;

	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH);

	wcex.hIcon = hIcon;
	wcex.hIconSm = hIcon;

	wcex.lpszClassName = WindowClass;

	wcex.lpszMenuName = nullptr;

	wcex.hInstance = HInstance();

	wcex.lpfnWndProc = WindowProcess;

	//RegisterClassEx(&wcex);

	if (!RegisterClassEx(&wcex)) {
		MessageBox(0, L"Failed to register window class.", 0, 0);
		exit(EXIT_FAILURE);
	}


}

VOID InitializeWIndow()
{
	HWND hWnd = CreateWindow(WindowClass, WindowTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, WindowWidth, WindowHeight, nullptr, nullptr, HInstance(), nullptr);

	if (!hWnd) {
		MessageBox(0, L"Failed to create window.", 0, 0);
		exit(EXIT_FAILURE);
	};



	ShowWindow(hWnd, SW_SHOW);

}

VOID MessageLoop()
{
	MSG msg{ 0 };

	while (msg.message != WM_QUIT) {
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}


	return VOID();

}
