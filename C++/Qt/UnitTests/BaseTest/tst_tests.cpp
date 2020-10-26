#include <QtTest>

class Test_MyClass : public QObject
{
    Q_OBJECT

private:
    bool condition()
    {
        return true;
    }

private slots:
    void initTestCase()
    {
        qDebug() << "initTestCase method\n";
    }

    void test_one()
    {
        QVERIFY(true);
        QCOMPARE(1, 1);
    }

    void test_condition()
    {
        QVERIFY(condition());
        QVERIFY(1 != 2);
    }

    void cleanupTestCase()
    {
        qDebug() << "cleanupTestCase method\n";
    }
};

QTEST_MAIN(Test_MyClass)
#include "tst_tests.moc"
