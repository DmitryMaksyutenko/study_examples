#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>

#pragma comment(linker, "/subsystem:windows")
#pragma comment(lib, "d2d1")

#include "baseWindow.h"
#include "MainWindow.h"

int WINAPI wWinMain(HMODULE hInstance, HMODULE hPrevInstance, PWSTR lpCmdLine, int nCmdShow)
{
    ooBase::MainWindow m_window;

    if (!m_window.Create(L"Circle", WS_OVERLAPPEDWINDOW))
        return 0;

    ShowWindow(m_window.Window(), nCmdShow);

    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}