#include <QCoreApplication>
#include <QPoint>  // Point with decimal numbers.
#include <QPointF> // Point with float numbers.

#include <iostream>

int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);

    // In the case of addition or subtraction, the coordinates of the points will be summarized or subtracted by pares.
    QPoint pt1(12, 24);
    QPoint pt2(3, 65);
    QPoint resPoint1;
    QPoint resPoint2;
    resPoint1 = pt1 + pt2;
    resPoint2 = pt1 - pt2;

    std::cout << "Addition\n";
    std::cout << "x: " << pt1.x() << " y: " << pt1.y() << "\n";
    std::cout << "x: " << pt2.x() << " y: " << pt2.y() << "\n";
    std::cout << "Result:\n";
    std::cout << "x: " << resPoint1.x() << " y: " << resPoint1.y() << "\n";

    std::cout << std::endl;

    std::cout << "Subtraction\n";
    std::cout << "x: " << pt1.x() << " y: " << pt1.y() << "\n";
    std::cout << "x: " << pt2.x() << " y: " << pt2.y() << "\n";
    std::cout << "Result:\n";
    std::cout << "x: " << resPoint2.x() << " y: " << resPoint2.y() << "\n";

    //	Points object can be multiplied or divided on a number.
    QPointF pt3(3.3, 1.4);
    QPointF pt4(5.5, 4.8);
    QPointF resPoint3;
    QPointF resPoint4;
    resPoint3 = pt3 * 3;
    resPoint4 = pt4 / 2.4;

    std::cout << std::endl;

    std::cout << "Multiplying\n";
    std::cout << "x: " << pt3.x() << " y: " << pt3.y() << "\n";
    std::cout << "x on 3\n";
    std::cout << "Result:\n";
    std::cout << "x: " << resPoint3.x() << " y: " << resPoint3.y() << "\n";

    std::cout << std::endl;

    std::cout << "Division\n";
    std::cout << "x: " << pt4.x() << " y: " << pt4.y() << "\n";
    std::cout << "/ on 2.4\n";
    std::cout << "Result:\n";
    std::cout << "x: " << resPoint4.x() << " y: " << resPoint4.y() << "\n";

    std::cout << std::endl;

    //	Referenco to coordinate.
    resPoint1.rx() = 0;
    resPoint1.ry() = 0;
    std::cout << "x: " << resPoint1.x() << " y: " << resPoint1.y() << "\n";

    //	Points can be compared.

    std::cout << std::endl;

    bool resultComp1 = pt1 == pt2;
    pt2.rx() = pt1.rx();
    pt2.ry() = pt1.ry();
    bool resultComp2 = pt1 == pt2;
    std::cout << std::boolalpha << resultComp1 << "\n";
    std::cout << std::boolalpha << resultComp2 << "\n";

    //	Checking for null.
    std::cout << std::endl;
    std::cout << std::boolalpha << pt1.isNull();

    return app.exec();
}
