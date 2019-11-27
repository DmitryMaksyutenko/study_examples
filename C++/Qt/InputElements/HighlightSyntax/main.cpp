#include "syntaxhighlighter.h"

#include <QApplication>
#include <QTextEdit>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTextEdit text;
    QFont font("Lucida Console", 9, QFont::Normal);
    text.document()->setDefaultFont(font);

    new SyntaxHighlighter(text.document());

    QPalette palette = text.palette();
    palette.setColor(QPalette::Base, Qt::darkBlue);
    palette.setColor(QPalette::Text, Qt::yellow);
    text.setPalette(palette);

    text.show();
    text.resize(640, 480);

    QFile file("D:\\Projects\\Qt\\SyntaxHighlight\\syntaxhighlighter.cpp");
    file.open(QFile::ReadOnly);
    text.setPlainText(QLatin1String(file.readAll()));

    return a.exec();
}
