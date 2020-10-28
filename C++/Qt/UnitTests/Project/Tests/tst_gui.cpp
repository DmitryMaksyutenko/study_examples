#include "tst_gui.h"

#include <QTest>

void TestGui::test_text()
{
    QString testText = "Some text";
    GUI g;
    g.setText(testText);

    QCOMPARE(testText, g.text());
}

QTEST_MAIN(TestGui)
