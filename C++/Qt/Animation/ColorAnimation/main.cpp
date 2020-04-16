#include <QApplication>
#include <QtWidgets>

void animationSettings(QPropertyAnimation &anim, QGraphicsColorizeEffect &eff, int time)
{
    anim.setTargetObject(&eff);
    anim.setPropertyName("color");
    anim.setStartValue(QColor(Qt::gray));
    anim.setKeyValueAt(0.25f, QColor(Qt::green));
    anim.setKeyValueAt(0.5f, QColor(Qt::blue));
    anim.setKeyValueAt(0.75f, QColor(Qt::red));
    anim.setEndValue(QColor(Qt::black));
    anim.setDuration(time);
}

int main(int argc, char **argv)
{
   QApplication app(argc, argv);

   QWidget main;

   QHBoxLayout hLayoutL;
   QHBoxLayout hLayoutR;
   QVBoxLayout vLayout;

   QGroupBox seq("Sequential");
   QGroupBox par("Parallel");

   QLabel lbl1;
   lbl1.setPixmap(QPixmap(":img/Linux.png"));
   QLabel lbl2;
   lbl2.setPixmap(QPixmap(":img/Android.png"));
   QLabel lbl3;
   lbl3.setPixmap(QPixmap(":img/MacOSX.png"));
   QLabel lbl4;
   lbl4.setPixmap(QPixmap(":img/Windows.png"));

   hLayoutL.addWidget(&lbl1);
   hLayoutL.addWidget(&lbl2);

   hLayoutR.addWidget(&lbl3);
   hLayoutR.addWidget(&lbl4);

   par.setLayout(&hLayoutL);
   seq.setLayout(&hLayoutR);

   vLayout.addWidget(&par);
   vLayout.addWidget(&seq);

   QGraphicsColorizeEffect e1;
   QGraphicsColorizeEffect e2;
   QGraphicsColorizeEffect e3;
   QGraphicsColorizeEffect e4;

   QPropertyAnimation a1;
   QPropertyAnimation a2;
   QPropertyAnimation a3;
   QPropertyAnimation a4;

   animationSettings(a1, e1, 3000);
   animationSettings(a2, e2, 3000);
   animationSettings(a3, e3, 5000);
   animationSettings(a4, e4, 5000);

   lbl1.setGraphicsEffect(&e1);
   lbl2.setGraphicsEffect(&e2);
   lbl3.setGraphicsEffect(&e3);
   lbl4.setGraphicsEffect(&e4);

   QParallelAnimationGroup pGroup;
   pGroup.addAnimation(&a1);
   pGroup.addAnimation(&a2);

   QSequentialAnimationGroup sGroup;
   sGroup.addAnimation(&a3);
   sGroup.addAnimation(&a4);

   pGroup.start();
   sGroup.start();

   main.setLayout(&vLayout);
   main.show();

   return app.exec();
}
