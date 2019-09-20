#include "MainWindow.h"


void MainWindow::CalculateLayout()
{}

HRESULT MainWindow::CreateGraphicsResuorce()
{
    HRESULT hr = S_OK;
    if (pRenderTarget == NULL)
    {
        RECT rc;
        GetClientRect(m_hwnd, &rc);
        D2D1_SIZE_U size = D2D1::SizeU(rc.right, rc.bottom);

        hr = pFactory->CreateHwndRenderTarget(
            D2D1::RenderTargetProperties(),
            D2D1::HwndRenderTargetProperties(m_hwnd, size),
            &pRenderTarget
        );

        if (SUCCEEDED(hr))
        {
            const D2D1_COLOR_F color = D2D1::ColorF(1.0f, 1.0f, 0);
            hr = pRenderTarget->CreateSolidColorBrush(color, &pBrush);

            if (SUCCEEDED(hr))
                CalculateLayout();
        }
    }
    return hr;
}

void MainWindow::DiscardGraphicsResources()
{
    SafeRelease(&pRenderTarget);
    SafeRelease(&pBrush);
}

void MainWindow::OnPaint()
{
    HRESULT hr = CreateGraphicsResuorce();
    if (SUCCEEDED(hr))
    {
        PAINTSTRUCT ps;
        BeginPaint(m_hwnd, &ps);
        pRenderTarget->BeginDraw();
        pRenderTarget->Clear(D2D1::ColorF(D2D1::ColorF::SkyBlue));
        pRenderTarget->FillEllipse(ellipse, pBrush);

        hr = pRenderTarget->EndDraw();
        if (FAILED(hr) || hr == D2DERR_RECREATE_TARGET)
            DiscardGraphicsResources();
        
        EndPaint(m_hwnd, &ps);
    }
}

void MainWindow::Resize()
{
    if (pRenderTarget != NULL)
    {
      RECT rc;
      GetClientRect(m_hwnd, &rc);  
      D2D1_SIZE_U size = D2D1::SizeU(rc.right, rc.bottom);
      pRenderTarget->Resize(size);
      CalculateLayout();
      InvalidateRect(m_hwnd, NULL, FALSE);
    }
}

PCWSTR MainWindow::ClassName() const
{
    return L"Circle Window Class!";
}

void MainWindow::OnButtonDown(int pixelX, int pixelY, DWORD flags)
{
    SetCapture(m_hwnd);// Function start capturing the mause.
    ellipse.point = ptMouse = DPIScale::PixelsToDips(pixelX, pixelY);
    ellipse.radiusX = ellipse.radiusY = 1.0f;
    InvalidateRect(m_hwnd, NULL, FALSE);// Function forces the window to be repained.
}

void MainWindow::OnMouseMove(int pixelX, int pixelY, DWORD flags)
{
    if(flags & MK_LBUTTON)
    {
        const D2D1_POINT_2F dips = DPIScale::PixelsToDips(pixelX, pixelY);
        const float width = (dips.x - ptMouse.x) / 2;
        const float height = (dips.y - ptMouse.y) / 2;
        const float x1 = ptMouse.x + width;
        const float y1 = ptMouse.y + height;
        ellipse = D2D1::Ellipse(D2D1::Point2F(x1, y1), width, height);
        InvalidateRect(m_hwnd, NULL, FALSE);
    }
}

void MainWindow::OnButtonUp()
{
    ReleaseCapture();
}

LRESULT MainWindow::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    wchar_t msg[32];
    switch(uMsg)
    {
        case WM_CREATE:
            if(FAILED(D2D1CreateFactory(
                D2D1_FACTORY_TYPE_SINGLE_THREADED, &pFactory)))
                return -1;
                DPIScale::Initialize(pFactory);
            return 0;

        case WM_DESTROY:
            DiscardGraphicsResources();
            SafeRelease(&pFactory);
            PostQuitMessage(0);
            return 0;

        case WM_PAINT:
            OnPaint();
            return 0;

        case WM_SIZE:
            Resize();
            return 0;

        case WM_LBUTTONDOWN:
            OnButtonDown(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam), (DWORD)wParam);
            return 0;
        
        case WM_LBUTTONUP:
            OnButtonUp();
            return 0;

        case WM_MOUSEMOVE:
            OnMouseMove(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam), (DWORD)wParam);
            return 0;

        case WM_SYSKEYDOWN:
            swprintf_s(msg, L"WM_SYSKEYDOWN: 0x%x\n", wParam);
            MessageBoxW(m_hwnd, msg, L"Information", NULL);
            return 0;

        case WM_SYSCHAR:
            swprintf_s(msg, L"WM_SYSCHAR: %c\n", (wchar_t)wParam);
            MessageBoxW(m_hwnd, msg, L"Information", NULL);
            return 0;

        case WM_SYSKEYUP:
            swprintf_s(msg, L"WM_SYSKEYUP: 0x%x\n", wParam);
            MessageBoxW(m_hwnd, msg, L"Information", NULL);
            return 0;

        case WM_KEYDOWN:
            swprintf_s(msg, L"WM_KEYDOWN: 0x%x\n", wParam);
            MessageBoxW(m_hwnd, msg, L"Information", NULL);
            return 0;

        case WM_KEYUP:
            swprintf_s(msg, L"WM_KEYUP: 0x%x\n", wParam);
            MessageBoxW(m_hwnd, msg, L"Information", NULL);
            return 0;

        case WM_CHAR:
            swprintf_s(msg, L"WM_SYSCHAR: %c\n", (wchar_t)wParam);
            MessageBoxW(m_hwnd, msg, L"Information", NULL);
            return 0;
    }
    return DefWindowProc(m_hwnd, uMsg, wParam, lParam);
}