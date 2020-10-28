#ifndef TST_GUI_H
#define TST_GUI_H

#include "../SourceCode/gui.h"

class TestGui : public QObject
{
    Q_OBJECT

public:
    TestGui()
    {

    }

    ~TestGui()
    {

    }

private slots:
    void test_text();

};

#endif // TST_GUI_H
