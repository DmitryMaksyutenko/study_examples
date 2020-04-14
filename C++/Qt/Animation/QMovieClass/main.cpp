#include <QApplication>
#include <QtWidgets>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QWidget mainWindow;
    QLabel lbl;
    QMovie movie(":img/Fly-Linux.gif");
    QTextEdit info;
    QVBoxLayout layout;

    movie.start();

    info.append("File name: " + movie.fileName());
    info.append("Loop count: " + QString::number(movie.loopCount()));
    info.append("Next frame delay: " + QString::number(movie.nextFrameDelay()));
    info.append("Speed: " + QString::number(movie.speed()));
    info.append("Background color: " + QString(movie.backgroundColor().name()));
    info.append("Current frame number: " + QString::number(movie.currentFrameNumber()));

    lbl.setMovie(&movie);
    lbl.resize(movie.frameRect().size());

    layout.addWidget(&lbl);
    layout.addWidget(&info);
    layout.setAlignment(&lbl, Qt::AlignCenter);

    mainWindow.setGeometry(700, 300, 500, 500);
    mainWindow.setLayout(&layout);
    mainWindow.show();

    return app.exec();
}
