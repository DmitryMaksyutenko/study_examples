#ifndef GUI_H
#define GUI_H

#include <QLabel>

class GUI : public QLabel
{
    Q_OBJECT
public:
    GUI(QObject *obj = nullptr);
};

#endif // GUI_H
