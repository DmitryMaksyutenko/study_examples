#include <QCoreApplication>
#include <qsound.h>

int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);

    QSound track(":/file_example_WAV_1MG.wav");
    track.setLoops(3);
    track.play();

    return app.exec();
}
