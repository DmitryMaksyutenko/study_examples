#include <QtCore>
#include <QVector>
#include <QList>
#include <QQueue>

/*	Container 	|	Access	|	Insertion/Deletion	|	Add to end 	|	Add to start
|-----------------------------------------------------------------------------------|
|	QList	  	|	Quickly	|		Slowly			|	Quickly		|	Quickly		|
|   QQueue	  	|			|						|				|				|
|-----------------------------------------------------------------------------------|
|	QVector	  	|	Quickly	|		Slowly			|	Quickly		|	Slowly		|
|   QStack 	  	|			|						|				|				|
|-----------------------------------------------------------------------------------|
|	QLinkedList	|	Slowly	|		Quickly			|	Quickly		|	Quickly		|
|-----------------------------------------------------------------------------------|
*/

//	QByteArray - class for store elements of byte size.
//	QBitArray - class for store elemants of bit size.


int main()
{
    /*
        push_front(), prepend(), pop_front() remove()
        inefficient methods.
    */
    qDebug() << "----- QVECTOR -----";
    QVector<int> vector {10, 20, 30};
    QVector<int>::iterator iVector = vector.begin();
    for(; iVector != vector.end(); ++iVector)
        qDebug() << *iVector;
    vector.push_back(40);
    qDebug() << "-------------------";
    for(iVector = vector.begin(); iVector != vector.end(); ++iVector)
        qDebug() << *iVector;

    qDebug() << "------ QLIST ------";
    QList<int> list = vector.toList();
    QList<int>::iterator iList;

    foreach (int i, list) {
       qDebug() << i;
    }
    qDebug() << "-------------------";
    for(iList = list.begin(); iList != list.end(); ++iList)
        qDebug() << *iList;
    list.push_back(50);

    qDebug() << "------ QQueue -----";
    QQueue<int> queue;
    int index = 0;
    for(iList = list.begin(); iList != list.end(); ++iList)
        queue.push_back(*iList);
    while(index != queue.size())
    {
        qDebug() << queue[index] << queue.size();
        queue.removeOne(index);
        index++;
    }

    return 0;
}
