#ifndef SYNTAXHIGHLIGHTER_H
#define SYNTAXHIGHLIGHTER_H

#include <QSyntaxHighlighter>
#include <QTextDocument>

class SyntaxHighlighter : public QSyntaxHighlighter
{
    Q_OBJECT

private:
    QStringList keyWords;

protected:
    enum {NormalState = -1, InsideCStyleComment, InsideCString};
    virtual void highlightBlock(const QString &str);
    QString getKeyword(int i,const QString &str) const;

public:
    SyntaxHighlighter(QTextDocument *parent = nullptr);
};
#endif // SYNTAXHIGHLIGHTER_H
