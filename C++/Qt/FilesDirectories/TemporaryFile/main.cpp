#include <QTemporaryFile>
#include <QFile>
#include <QByteArray>
#include <QDebug>

int main()
{
  QTemporaryFile tmpFile("testName");
  tmpFile.open();
  qDebug() << "Open mode: " << tmpFile.openMode();

  qDebug() << "Does file exists: " << tmpFile.exists();
  qDebug() << "File full path name: " << tmpFile.fileName();
  qDebug() << "Does file exists: " << tmpFile.exists();

  qDebug() << "File size: " << tmpFile.size();
  tmpFile.write("Some data");
  qDebug() << "File size: " << tmpFile.size();
  tmpFile.seek(0);
  QByteArray byteArray = tmpFile.readAll();
  qDebug() << byteArray;

  tmpFile.close();
  qDebug() << "Does file exists: " << tmpFile.exists();

  return 0;
}
