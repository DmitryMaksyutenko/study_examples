#include <QApplication>
#include <QDesktopServices>
#include <QUrl>
#include <QDir>
#include <QDebug>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  bool browserResult = QDesktopServices::openUrl(QUrl("https://google.com"));
  QString filePath = QDir::home().filePath(".vimrc");
  bool fileResult = QDesktopServices::openUrl(QUrl::fromLocalFile(filePath));

  qDebug() << "Does browser opend: " << browserResult;
  qDebug() << "Does file opend: " << fileResult;

  return a.exec();
}
