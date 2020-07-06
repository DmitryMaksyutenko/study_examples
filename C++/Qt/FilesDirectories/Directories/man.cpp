#include <QCoreApplication>
#include <QDir>
#include <QDebug>

int main(int argc, char **argv)
{
  QCoreApplication app(argc, argv);
  QString exeDirPath = app.applicationDirPath();
  QString appName = app.applicationName();

  qDebug() << "Path to executable file: " << exeDirPath;
  qDebug() << "Applicatin name: " << appName;

  qDebug() << "Home dir: " << QDir::homePath();
  qDebug() << "Root directory: " << QDir::rootPath();

  QDir dir = QDir::current();
  dir.cdUp();
  qDebug() << "Parent dir path: " << dir.path();

  qDebug() << dir.mkdir("test_dir");

  if (dir.exists("test_dir"))
    qDebug() << dir.rmdir("test_dir");

  qDebug() << "Elements in " << dir.path() << " : " << dir.count();

  QStringList inDir = dir.entryList();
  for (QString elem : inDir) {
    qDebug() << elem;
  }

  QFileInfoList infoList = dir.entryInfoList();
  foreach (QFileInfo infoItem, infoList) {
    qDebug() << infoItem;
  }

  return 0;
}
