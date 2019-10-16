#include <QCoreApplication>
#include <QtGlobal>
#include <QFile>
#include <QDateTime>
#include <QTextStream>
#include <QDebug>

void dumpOutput(QtMsgType, const QMessageLogContext&, const QString&) {}

void messageToFile(QtMsgType type,
                   const QMessageLogContext &context,
                   const QString &msg)
{
    QFile file("protocol.log");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
        return;

    QString strDateTime = QDateTime::currentDateTime().toString("dd.MM.yy-hh:mm");

    QTextStream out(&file);

    switch (type) {
        case QtDebugMsg:
            out << strDateTime << " Debug: " << msg << ", " << context.file << endl;
        break;

    case QtWarningMsg:
            out << strDateTime << " Warning: " << msg << ", " << context.file << endl;
        break;

    case QtCriticalMsg:
            out << strDateTime << " Critical: " << msg << ", " << context.file << endl;
        break;

    case QtFatalMsg:
            out << strDateTime << " Fatal: " << msg << ", " << context.file << endl;
        abort();
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInstallMessageHandler(messageToFile);
#ifndef QT_DEBUG
    qInstallMessageHandler(dumpOutput);
#endif

    qDebug() << "Message in qDebug";
    qWarning() << "Message in qWarning";
    qCritical() << "Message in qCritical";
    qFatal("Fatal message");

    return a.exec();
}
