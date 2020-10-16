#include "widget.h"

#include <windows.h>

void Widget::resizeEvent(QResizeEvent *event)
{
    update();
    QWidget::resizeEvent(event);
}

bool Widget::nativeEvent(const QByteArray &bArr, void *message, long *result)
{
    QString str1 = "Windows wersion = " + QString::number(QSysInfo::WindowsVersion);
    QString str2 = "Windows message.";

    WId	id = effectiveWinId();
    HWND hwnd = (HWND)id;
    MSG *msg = reinterpret_cast<MSG *>(message);

    switch (msg->message) {
        case WM_RBUTTONDOWN:
            ::MessageBox(hwnd,
                         (const char *)str1.utf16(),
                         (const char *)str2.utf16(),
                         MB_OK | MB_ICONEXCLAMATION);
        break;
        default:
        break;
    }
    return QWidget::nativeEvent(bArr, message, result);
}

void Widget::paintEvent(QPaintEvent *event)
{
    WId id = effectiveWinId();
    HWND hwnd = (HWND)id;
    HDC hdc = ::GetDC(hwnd);
    HBRUSH hBrush = ::CreateSolidBrush(RGB(255, 0, 255));
    HBRUSH hBrushRect = ::CreateSolidBrush(RGB(200,200, 200));
    HPEN pen = ::CreatePen(PS_SOLID, 2, RGB(0, 0, 128));
    QString str = "GDI Drawing.";
    TEXTMETRIC tm;

    ::SelectObject(hdc, hBrushRect);
    ::Rectangle(hdc, 0, 0, width(), height());
    ::GetTextMetricsA(hdc, &tm);
    ::SelectObject(hdc, hBrush);
    ::SelectObject(hdc, pen);
    ::Ellipse(hdc, 0, 0, width(), height());
    ::TextOutA(hdc,
              width() / 2 - (tm.tmAveCharWidth * str.length()) / 2,
              (height() - tm.tmHeight) / 2,
              (const CHAR*)str.utf16(),
              str.length());
    ::DeleteObject(hBrushRect);
    ::DeleteObject(hBrush);
    ::DeleteObject(pen);
    ::ReleaseDC(hwnd, hdc);
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setAutoFillBackground(true);
    setAttribute(Qt::WA_PaintOnScreen, true);
}

Widget::~Widget()
{
}

QPaintEngine *Widget::paintEngine() const
{
    return nullptr;
}

