#include <QApplication>
#include <QObject>
#include <QDebug>

int main()
{
    // Creates an object hierarchy.
    // Set base object pobj1, it has two child pobj2 and pobj3.
    // The pobj2 has one child pobj4.
    QObject *pobj1 = new QObject;
    QObject *pobj2 = new QObject(pobj1);
    QObject *pobj3 = new QObject(pobj1);
    QObject *pobj4 = new QObject(pobj2);

    // setObjectName - self-titled method.
    pobj1->setObjectName("This is the base object");
    pobj2->setObjectName("The first object pobj1 child 'pobj2'");
    pobj3->setObjectName("The second object pobj1 child 'pobj3'");
    pobj4->setObjectName("the first object pobj2 child 'pobj4'");

    qDebug() << "\n----- Show parents -----";

    // In loop create a new pointer to the object and assign it pobj4.
    // In each iteration reassigned to in new pointer to the parent object
    // of the current object while not get the base object. For the base object parent() method will return zero.
    for (QObject *pobj = pobj4; pobj; pobj = pobj->parent())
        qDebug() << pobj->objectName();

    qDebug() << "\n----- Show children of base object -----";

    // In range loop with children() method help, prints name of the child in each iteration.
    for (auto &a : pobj1->children())
        qDebug() << a->objectName();

    // Create list Qt object and assign to it children of base object find with regular expression.
    QList<QObject *> listOfChild = pobj1->findChildren<QObject *>(QRegExp("Th*"));

    qDebug() << "\n----- Show list of children find with regular expression -----";

    for (int i = 0; i < listOfChild.size(); ++i)
        qDebug() << listOfChild[i]->objectName();

    // Just return all.
   QList<QObject *> all = pobj1->findChildren<QObject *>();

   qDebug() << "\n----- Show all children -----";
   for (auto &i : all)
       qDebug() << i->objectName();

   // This method helps to debug.
   qDebug() << "\n----- Show dump info -----";
   pobj1->dumpObjectInfo();
   qDebug();
   pobj4->dumpObjectInfo();

   // This method show object hierarchy in stdout flow as a tree.
   qDebug() << "\n----- Tree hierarchy -----";
   pobj1->dumpObjectTree();

    return  0;
}
