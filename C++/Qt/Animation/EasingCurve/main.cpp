#include <QApplication>
#include <QtWidgets>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QLabel lbl1("window 1");
    QLabel lbl2("window 2");

    QPropertyAnimation anim1(&lbl1, "pos");
    anim1.setDuration(3000);
    anim1.setStartValue(QPoint(240, 0));
    anim1.setEndValue(QPoint(240, 480));
    anim1.setEasingCurve(QEasingCurve::OutBounce);

    QPropertyAnimation anim2(&lbl2, "geometry");
    anim2.setDuration(3000);
    anim2.setStartValue(QRect(120, 0, 100, 100));
    anim2.setEndValue(QRect(480, 380, 200, 200));
    anim2.setEasingCurve(QEasingCurve::InOutExpo);

    QParallelAnimationGroup group;
    group.addAnimation(&anim1);
    group.addAnimation(&anim2);
    group.setLoopCount(3);
    group.start();

    lbl1.show();
    lbl2.show();

    return app.exec();
}
