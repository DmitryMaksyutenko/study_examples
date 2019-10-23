#include <QRegExp> // The class for work with regular expressions
#include <QDebug>

/*
    .	:	Any symbol.
    []	:	Any from the set.
    $	:	The row end.
    -	:	Define the range of the symbols.
    ^	:	The beginning of the row.
    *	:	The symbol must appear in the row repeatedly or never.
    +	:	The symbol must appear in the row at least once.
    ?	:	The symbol must appear in the row at least once or never.
    {n}	:	The symbol must appear in the row specified numbers of times.
   {n,} :	Allows a minimum of n coincidence.
   {,n} :	Allows n coincidence.
  {n,m} :	Allows from n to m coincidence.
    |	:	Searches one of two symbols.
    \b	:	A word.
    \B	:	Not a word.
    ()	:	The set of symbols.
    \d	:	Any digit.
    \D	:	Any except the digit.
    \s	:	Any space type.
    \S	:	Any except the space.
    \w	:	Any letter, digit, underscore.
    \W	:	All except letter.
    \A	:	The beginning of the string.
    \z	:	The end of the string (a coincidence with the last character or before the new line character).
    \Z	:	The end of the string (a coincidence with the last character).
*/

int main()
{
    QString definition {"The regular expression is a powerful tool to analyze and handle the strings."};
    qDebug() << definition;

    QRegExp reg ("[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}") ;
    QString str("this is an ip-address 123.222.63.1 lets check it");
    qDebug() << (str.contains(reg) > 0);

    QRegExp rxp("(.com|.ru)");
    int n1 = rxp.indexIn("www.bhv.ru");
    int n2 = rxp.indexIn("www.bhv.de");
    qDebug() << "n1 " << n1;
    qDebug() << "n2 " << n2;

    QRegExp email("^([a-zA-Z0-9_]+)@([a-zA-Z0-9_-])+\\.([a-z]{1,4})$");
    QString e1 {"myemail@google.com"};
    QString e2 {"teest#gmail.com"};
    QString e3 {"loooooo@mailxcom"};
    bool fst = email.exactMatch(e1);
    bool scd = email.exactMatch(e2);
    bool thd = email.exactMatch(e3);

    qDebug() << "e1 " << fst;
    qDebug() << "e2 " << scd;
    qDebug() << "e3 " << thd;

    return 0;
}
