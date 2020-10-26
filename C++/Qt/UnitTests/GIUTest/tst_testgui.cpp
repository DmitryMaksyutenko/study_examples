#include <QtTest>

#include <QLineEdit>

// add necessary includes here

class TestGui : public QObject
{
    Q_OBJECT

public:
    TestGui();
    ~TestGui();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_QLineEdit();

};

TestGui::TestGui()
{

}

TestGui::~TestGui()
{

}

void TestGui::initTestCase()
{

}

void TestGui::cleanupTestCase()
{

}

void TestGui::test_QLineEdit()
{
    QLineEdit obj;

    QTest::keyClicks(&obj, "some text");

    QCOMPARE(obj.text(), QString("some text"));

}

QTEST_MAIN(TestGui)

#include "tst_testgui.moc"
