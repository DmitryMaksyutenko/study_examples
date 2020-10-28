#include "tst_testadd.h"

#include <QTest>

void TestAdd::test_addition()
{
    Add a;
    QCOMPARE(2, a.addition(1, 1));
}


QTEST_APPLESS_MAIN(TestAdd)
