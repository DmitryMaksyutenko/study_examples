#include "widget.h"

Widget::Widget(QLineEdit *log, QLineEdit *pass, QTextEdit *info ,QWidget *parent) :
    QWidget(parent),
    login(log),
    password(pass),
    information(info)

{
    QWidget *newWindow = new QWidget();
    QLabel *displayPassword = new QLabel();
    displayPassword->setFrameStyle(QFrame::Box | QFrame::Raised);
    displayPassword->setLineWidth(2);
    displayPassword->setFixedHeight(50);
    \
    QLabel *loginLabel = new QLabel("login: ");
    QLabel *passLabel = new QLabel("password: ");

    connect(password, SIGNAL(textChanged(const QString&)),
            displayPassword, SLOT(setText(const QString&)));

    connect(information, SIGNAL(textChanged()),
            newWindow, SLOT(show()));

    QVBoxLayout *vBox = new QVBoxLayout();
    vBox->addWidget(displayPassword);
    vBox->addWidget(loginLabel);
    vBox->addWidget(login);
    vBox->addWidget(passLabel);
    vBox->addWidget(password);
    vBox->addWidget(information);

    setLayout(vBox);
}

Widget::~Widget()
{
}

