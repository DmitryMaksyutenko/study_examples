#include <QtTest>

// add necessary includes here

class TestString : public QObject
{
    Q_OBJECT

public:
    TestString();
    ~TestString();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1_data();
    void test_case1();

};

TestString::TestString()
{

}

TestString::~TestString()
{

}

void TestString::initTestCase()
{

}

void TestString::cleanupTestCase()
{

}

void TestString::test_case1_data()
{
    QTest::addColumn<QString>("string");
    QTest::addColumn<QString>("result");

    QTest::newRow("all lower") << "hello" << "hello";
    QTest::newRow("is equal") << "hellO" << "hellO";
    QTest::newRow("all upper") << "HELLO" << "HELLO";
}

void TestString::test_case1()
{
    QFETCH(QString, string);
    QFETCH(QString, result);

    QCOMPARE(string, result);
}

QTEST_APPLESS_MAIN(TestString)

#include "tst_teststring.moc"
