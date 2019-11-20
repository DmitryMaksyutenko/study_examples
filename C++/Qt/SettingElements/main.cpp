#include "widget.h"

#include <QApplication>

#include <QSlider>
#include <QScrollBar>
#include <QDial>

#include <QLCDNumber>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QProgressBar>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

    //	If needs to inherit from QAbstractSlider, override the method sliderChange().
    //	Use setOrientation() SLOT for changing layout, Qt::Vertical, Qt::Horizontal.
    //	For range definition use setRange(min, max) or setMinimum(val), setMaximum(val).
    //	setSingleStep(val) - use for step definition.
    //	setPageStep(val) - page scroll.
    //	setValue(val) - SLOT defines the value, value() - return current value.
    //	The sliderMoved() SIGNAL emits when the user changes the position of the slider and returns the current value.
    //	The valueChanged(int) - passed simultaneously with the slideMoves(), can be modified by setTraqcking(false) - sent when user release the slider.
    //	sliderPressed(), sliderRelised() - SIGALS

    QSlider slider(Qt::Horizontal);
    slider.setRange(0, 9);
    slider.setPageStep(2);
    slider.setTickInterval(2);
    slider.setValue(3);
    slider.setTickPosition(QSlider::TicksBelow);

    QLabel labl_1("3");

    QObject::connect(&slider, SIGNAL(valueChanged(int)), &labl_1, SLOT(setNum(int)));

    QHBoxLayout hBox;
    hBox.addWidget(&slider);
    hBox.addWidget(&labl_1);
    w.setLayout(&hBox);


    //----------------------------------------------------------------------------

    QWidget w2;
    QLCDNumber lcdNum(4);
    QScrollBar scrollBar(Qt::Horizontal);
    scrollBar.setRange(0, 9999);

    QObject::connect(&scrollBar, SIGNAL(valueChanged(int)), &lcdNum, SLOT(display(int)));

    QHBoxLayout hBox2;
    hBox2.addWidget(&lcdNum);
    hBox2.addWidget(&scrollBar);
    w2.setLayout(&hBox2);
    w2.resize(250, 100);

    //-----------------------------------------------------------------------------

    QWidget w3;
    QDial dial;
    QProgressBar progressBar;

    dial.setRange(0, 99);
    dial.setNotchTarget(5);
    dial.setNotchesVisible(true);

    QObject::connect(&dial, SIGNAL(valueChanged(int)), &progressBar, SLOT(setValue(int)));

    QVBoxLayout vBox3;
    vBox3.addWidget(&dial);
    vBox3.addWidget(&progressBar);
    w3.setLayout(&vBox3);
    w3.resize(180, 200);

    w.show();
    w2.show();
    w3.show();
    return a.exec();
}
