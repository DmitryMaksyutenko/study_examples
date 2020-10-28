#ifndef TST_TESTADD_H
#define TST_TESTADD_H

#include "../SourceCode/add.h"

class TestAdd : public QObject
{
    Q_OBJECT

public:
    TestAdd()
    {

    }

    ~TestAdd()
    {

    }


private slots:
    void test_addition();

};

#endif // TST_TESTADD_H
