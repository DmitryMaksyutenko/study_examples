#include <QApplication>
#include <QtWidgets>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QGraphicsScene scene(QRectF(0, 0, 400, 400));
    QGraphicsView view(&scene);

    QPushButton quitButton("Quit");

    QGraphicsProxyWidget *proxy = scene.addWidget(&quitButton);

    QTransform transform = proxy->transform();
    transform.translate(100, 350);
    transform.rotate(-45, Qt::YAxis);
    transform.scale(8, 2);

    proxy->setTransform(transform);

    QObject::connect(&quitButton, SIGNAL(clicked()), &app, SLOT(quit()));

    QDial dia;
    dia.setNotchesVisible(true);
    proxy = scene.addWidget(&dia);
    transform = proxy->transform();
    transform.scale(4, 2);
    transform.rotate(-45, Qt::YAxis);

    QProgressBar progres;
    progres.setFixedSize(500, 40);
    proxy = scene.addWidget(&progres);
    transform = proxy->transform();
    transform.translate(20, 200);
    transform.scale(2, 2);
    transform.rotate(80, Qt::YAxis);
    transform.rotate(30, Qt::XAxis);
    proxy->setTransform(transform);

    QObject::connect(&dia, SIGNAL(valueChanged(int)), &progres, SLOT(setValue(int)));

    view.rotate(15);
    view.resize(500, 500);
    view.show();

    app.setStyle("Windows");

    return app.exec();
}
