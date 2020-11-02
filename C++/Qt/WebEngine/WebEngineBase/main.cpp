#include <QApplication>
#include <QtWidgets>
#include <QtWebEngineWidgets>
#include <QUrl>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWebEngineView webView;

    webView.load(QUrl("https://google.com"));
    webView.show();

    return a.exec();
}
