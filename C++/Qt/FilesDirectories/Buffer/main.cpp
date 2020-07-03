#include <QByteArray>
#include <QBuffer>
#include <QDir>
#include <QFile>
#include <QDebug>

int main()
{
  QByteArray byteArray;
  QBuffer buffer(&byteArray);
  QFile file(QDir::homePath() + "/.zshrc");

  if (!file.exists()) qWarning() << "File don't exists.";
  else {
    qDebug() << "File exists.";

    buffer.open(QIODevice::ReadWrite);
    file.open(QIODevice::ReadOnly);

    qint64 fileSize = file.size();
    buffer.write(file.readAll(), fileSize);

    QString bufferData = buffer.data();
    qDebug() << bufferData;

    file.close();
    buffer.close();
  }


  return 0;
}
