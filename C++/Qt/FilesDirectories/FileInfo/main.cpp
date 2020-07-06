#include <QDebug>
#include <QFile>
#include <QDir>
#include <QFileInfo>
#include <QDateTime>

int main()
{
  QFile file = QDir::homePath();
  QFileInfo fileInfo(file);

  qDebug() << "File path:" << fileInfo.path();
  qDebug() << "Is this a file:" << fileInfo.isFile();
  qDebug() << "Is this a directory:" << fileInfo.isDir();
  qDebug() << "File sieze:" << fileInfo.size();
  qDebug() << "File Owner:" << fileInfo.owner();
  qDebug() << "File created:" << fileInfo.birthTime();
  qDebug() << "File modified:" << fileInfo.lastModified().toString();
  qDebug() << "File hidden:" << fileInfo.isHidden();
  qDebug() << "File writable:" << fileInfo.isWritable();
  qDebug() << "File readable:" << fileInfo.isReadable();
  qDebug() << "File executable:" << fileInfo.isExecutable();

  return 0;
}
