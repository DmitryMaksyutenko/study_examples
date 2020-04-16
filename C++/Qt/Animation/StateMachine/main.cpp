#include <QApplication>
#include <QtWidgets>


int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QWidget wgt;
    wgt.setFixedSize(300, 50);
    wgt.show();

    QLabel off("Off");
    QLabel on("On");

    QHBoxLayout hBox;
    hBox.addWidget(&on);
    hBox.addStretch(1);
    hBox.addWidget(&off);

    wgt.setLayout(&hBox);

    QPushButton cmd("Push", &wgt);
    cmd.setAutoFillBackground(true);
    cmd.show();

    int buttonWidth = wgt.width() / 2;

    QStateMachine sm;

    QState stateOff(&sm);
    QRect rect1(0, 0, buttonWidth, wgt.height());

    stateOff.assignProperty(&cmd, "geometry", rect1);
    stateOff.assignProperty(&off, "visible", true);
    stateOff.assignProperty(&on, "visible", false);

    sm.setInitialState(&stateOff);

    QState stateOn(&sm);
    QRect rect2(buttonWidth, 0, buttonWidth, wgt.height());
    stateOn.assignProperty(&cmd, "geometry", rect2);
    stateOn.assignProperty(&off, "visible", false);
    stateOn.assignProperty(&on, "visible", true);

    QSignalTransition *tSignal1 =
            stateOff.addTransition(&cmd, SIGNAL(clicked()), &stateOn);

    QSignalTransition *tSignal2 =
            stateOn.addTransition(&cmd, SIGNAL(clicked()), &stateOff);


    QPropertyAnimation anim1(&cmd, "geometry");
    tSignal1->addAnimation(&anim1);

    QPropertyAnimation anim2(&cmd, "geometry");
    tSignal2->addAnimation(&anim2);

    sm.start();

    return app.exec();
}
