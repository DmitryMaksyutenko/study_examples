#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>
#include <windowsx.h> //  Macro APIs, window message crackers, and control APIs Version Win32 / Windows NT. 
#include <d2d1.h>

#pragma comment(linker, "/subsystem:windows")
#pragma comment(lib, "d2d1")

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
ID2D1Factory *pFactory;
ID2D1HwndRenderTarget *pRenderTarget;
ID2D1SolidColorBrush *pBrush;
D2D1_ELLIPSE elipse;
D2D1_POINT_2F ptMouse;
float scaleX;
float scaleY;

int WINAPI wWinMain(HMODULE hInstance, HMODULE hPrenInstance, PWSTR lpCmdLine, int nShowCmd)
{

    pFactory = NULL;
    pRenderTarget = NULL;
    pBrush = NULL;
    elipse = D2D1::Ellipse(D2D1::Point2F(), 0, 0);
    ptMouse = D2D1::Point2F();
    scaleX = 1.0f;
    scaleY = 1.0f;

    WNDCLASS windowClass {};
    windowClass.lpfnWndProc = WindowProc;
    windowClass.hInstance = hInstance;
    windowClass.lpszClassName = L"Circle";

    RegisterClass(&windowClass);

    HWND hwnd = CreateWindowEx(
        0,
        windowClass.lpszClassName,
        L"Circle window",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        NULL,
        NULL,
        hInstance,
        NULL
    );

    ShowWindow(hwnd, nShowCmd);

    MSG msg {};

    while(GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    

    return 0;
}


LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_CREATE:
        {
            if(FAILED(D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &pFactory)))
                return -1;
            return 0;
        }
        case WM_DESTROY:
        {
                PostQuitMessage(0);
                return 0;
        }
        case WM_PAINT:
        {
            if (pRenderTarget == NULL)
            {
                RECT rc;
                GetClientRect(hwnd, &rc);
                D2D1_SIZE_U size = D2D1::SizeU(rc.right, rc.bottom);

                if (SUCCEEDED(
                    pFactory->CreateHwndRenderTarget(
                        D2D1::RenderTargetProperties(), 
                        D2D1::HwndRenderTargetProperties(hwnd, size), 
                        &pRenderTarget)))
                {
                    const D2D1_COLOR_F color = D2D1::ColorF(1.0f, 1.0f, 1.0f);
                    pRenderTarget->CreateSolidColorBrush(color, &pBrush);
                }


            }

            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            pRenderTarget->BeginDraw();
            pRenderTarget->Clear(D2D1::ColorF(D2D1::ColorF::DarkGreen));
            pRenderTarget->EndDraw();

            EndPaint(hwnd, &ps);
        }
        case WM_LBUTTONDOWN:
        {
            // // To begin capture the mouse inside particular window belonging to the particular thread.
             SetCapture(hwnd);
            //  Convert  form DPI to DIPs pixels.
            FLOAT x, y;
            pFactory->GetDesktopDpi(&x, &y);
            scaleX = x / 96.0f;
            scaleY = y / 96.0f;
            
            //  Reset the ellipse structure.
            ptMouse = {static_cast<float>(GET_X_LPARAM(lParam)) / scaleX, 
                       static_cast<float>(GET_Y_LPARAM(lParam)) / scaleY};
            elipse.point = ptMouse;
            elipse.radiusX = 1.0f;
            elipse.radiusY = 1.0f;

            // InvalidateRect(hwnd, NULL, FALSE); // Funcion forces the window to be rapained.
            return 0;
        } 
        case WM_LBUTTONUP:
        {
            // Releases the mouse capture from a window in the current thread and restores normal mouse input processing.
            ReleaseCapture();
            return 0;
        } 
        case WM_MOUSEMOVE:
        {
            if (wParam & MK_LBUTTON) // If left mouse button is down.
            {
                FLOAT x, y;
                pFactory->GetDesktopDpi(&x, &y);
                scaleX = x / 96.0f;
                scaleY = y / 96.0f;
                const D2D1_POINT_2F dips ={static_cast<float>(GET_X_LPARAM(lParam)) / scaleX, 
                                            static_cast<float>(GET_Y_LPARAM(lParam)) / scaleY};

                const float width = (dips.x - ptMouse.x) / 2;
                const float heigth = (dips.y - ptMouse.y) / 2;
                const float x1 = ptMouse.x + width;
                const float y1 = ptMouse.y + heigth;

                elipse = D2D1::Ellipse(D2D1::Point2F(x1, y1), width, heigth);
                InvalidateRect(hwnd, NULL, FALSE);
                return 0;
            } 
        } 
            return 0;
    }

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
