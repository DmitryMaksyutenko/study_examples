#ifndef UNICODE
#define UNICODE
#endif

#include <Windows.h>
#include "mainWindow.h"

#pragma comment( linker, "/subsystem:windows" )

int WINAPI WinMain( HMODULE hInstance, HMODULE hPrevInstance, PSTR lpCmdLine, int nShowCmd )
{

	ShowWindow(GetConsoleWindow(), SW_HIDE);

	ooBase::MainWindow baseW;

	if (!baseW.Create(L"Test Window", WS_OVERLAPPEDWINDOW))
		return 0;

	ShowWindow(baseW.Window(), nShowCmd);

	MSG msg = {};
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}