#include "testwidget.h"

TestWidget::TestWidget() : QWidget()
{

}

void TestWidget::keyPressEvent(QKeyEvent *event)
{
    int keyNum = event->key();

    switch (keyNum)
    {
        case Qt::Key_A:
            if(event->modifiers() & Qt::ShiftModifier)
                emit keyAsString(QString(keyNum));
            else
                emit keyAsString("a");
            break;
        case Qt::Key_Q: emit keyAsString(event->text()); break;
        case Qt::Key_W: emit keyAsString(event->text()); break;
        case Qt::Key_E: emit keyAsString(event->text()); break;
        case Qt::Key_R: emit keyAsString(event->text()); break;
        case Qt::Key_T: emit keyAsString(event->text()); break;
        case Qt::Key_Y: emit keyAsString(event->text()); break;
        case Qt::Key_U: emit keyAsString(event->text()); break;
        case Qt::Key_I: emit keyAsString(event->text()); break;
        case Qt::Key_O: emit keyAsString(event->text()); break;
        case Qt::Key_P: emit keyAsString(event->text()); break;
        case Qt::Key_S: emit keyAsString(event->text()); break;
        case Qt::Key_D: emit keyAsString(event->text()); break;
        case Qt::Key_F: emit keyAsString(event->text()); break;
        case Qt::Key_G: emit keyAsString(event->text()); break;
        case Qt::Key_H: emit keyAsString(event->text()); break;
        case Qt::Key_J: emit keyAsString(event->text()); break;
        case Qt::Key_K: emit keyAsString(event->text()); break;
        case Qt::Key_L: emit keyAsString(event->text()); break;
        case Qt::Key_Z: emit keyAsString(event->text()); break;
        case Qt::Key_X: emit keyAsString(event->text()); break;
        case Qt::Key_C: emit keyAsString(event->text()); break;
        case Qt::Key_V: emit keyAsString(event->text()); break;
        case Qt::Key_B: emit keyAsString(event->text()); break;
        case Qt::Key_N: emit keyAsString(event->text()); break;
        case Qt::Key_M: emit keyAsString(event->text()); break;
        case Qt::Key_ParenLeft: emit keyAsString(event->text()); break;
        case Qt::Key_ParenRight: emit keyAsString(event->text()); break;
        case Qt::Key_Semicolon: emit keyAsString(event->text()); break;
        case Qt::Key_Colon: emit keyAsString(event->text()); break;
        case Qt::Key_Less: emit keyAsString(event->text()); break;
        case Qt::Key_Greater: emit keyAsString(event->text()); break;
        case Qt::Key_Space: emit keyAsString(event->text()); break;

        default: keyPressEvent(event);
    }
}
