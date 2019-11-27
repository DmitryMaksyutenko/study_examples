#ifndef INPUTVALIDATOR_H
#define INPUTVALIDATOR_H

#include <QValidator>
#include <QRegExp>

class InputValidator : public QValidator
{
    Q_OBJECT

public:
    InputValidator(QObject *parent = nullptr);
    ~InputValidator();

    virtual State validate(QString &str, int &pos) const
    {
        QRegExp rExp("[0-9]");

        if(str.contains(rExp))
            return QValidator::Invalid;

        return QValidator::Acceptable;
    }
};
#endif // INPUTVALIDATOR_H
