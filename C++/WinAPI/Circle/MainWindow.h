#include "baseWindow.h"
#include <d2d1.h>

namespace ooBase
{
    class MainWindow : public ooBase::BaseWindow<MainWindow>
    {
        private:
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
            MainWindow() : pFactory(NULL), pRenderTarget(NULL), pBrush(NULL) {}

            PCWSTR ClassName() const;
	    LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
    };
}

template <class T>
void SafeRelease(T **ppT)
{
    if (*ppT)
    {
        (*ppT)->Release();
        *ppT = NULL;
    }
}