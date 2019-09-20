#pragma once
#include "baseWindow.h"
#include <d2d1.h>

class MainWindow : public ooBase::BaseWindow<MainWindow>
{
    private:
        D2D1_POINT_2F ptMouse;
        ID2D1Factory *pFactory;
        ID2D1HwndRenderTarget *pRenderTarget;
        ID2D1SolidColorBrush *pBrush;
        D2D1_ELLIPSE ellipse;

        void CalculateLayout();
        HRESULT CreateGraphicsResuorce();
        void DiscardGraphicsResources();
        void OnPaint();
        void Resize();

    public:
        MainWindow() : pFactory(NULL), pRenderTarget(NULL), pBrush(NULL),
                    ellipse(D2D1::Ellipse(D2D1::Point2F(),0, 0)), ptMouse(D2D1::Point2F()) {}

        PCWSTR ClassName() const;
        LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
        void OnButtonDown(int pixelX, int pixelY, DWORD flags);
        void OnButtonUp();
        void OnMouseMove(int pixelX, int pixelY, DWORD flags);
};

template <class T>
void SafeRelease(T **ppT)
{
    if (*ppT)
    {
        (*ppT)->Release();
        *ppT = NULL;
    }
}


/* Mouse coordinates are given in phusical pixels, but Direct2D expects device-independent pixels (DIPs)
    This is helper class that convert pixels into DIPs.
*/
class DPIScale
{
    static float scaleX;
    static float scaleY;

    public:
        static void Initialize(ID2D1Factory *pFactory)
        {
            FLOAT dpiX, dpiY;
            pFactory->GetDesktopDpi(&dpiX, &dpiY);
            scaleX = dpiX / 96.0f;    
            scaleY = dpiY / 96.0f;    
        }

        template <typename T>
        static D2D1_POINT_2F PixelsToDips(T x, T y)
        {
            return D2D1::Point2F(static_cast<float>(x) / scaleX, static_cast<float>(y) / scaleY);
        }
};

//  For avoid error LNK2005 use __declspec(selectany), it tells lincer to pick one definition
//  for use by all external references and to discard the rest.
__declspec(selectany) float DPIScale::scaleX = 1.0f;
__declspec(selectany) float DPIScale::scaleY = 1.0f;