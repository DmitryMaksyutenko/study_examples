#include "mainwindow.h"

MainWindow::MainWindow()
{
    m_plcd = new QLCDNumber(12);	//	segments count
    m_plcd->setSegmentStyle(QLCDNumber::Flat);	//	set segments style
    m_plcd->setMinimumSize(150, 50);

    QChar aButtons[4][4] = {{'7', '8', '9', '/'},
                            {'4', '5', '6', '*'},
                            {'1', '2', '3', '-'},
                            {'0', '.', '=', '+'}};

    //	Layout setup
    QGridLayout *grid = new QGridLayout;
    grid->addWidget(m_plcd, 0, 0, 1, 4);	// set display in the top, and span one row and four columns.
    grid->addWidget(createButton("CE"), 1, 3);	 // set the CE button in the right under the display.

    //	the other buttons placing
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
            grid->addWidget(createButton(aButtons[i][j]), i + 2, j);
    }
    setLayout(grid);
}

MainWindow::~MainWindow()
{
}

QPushButton *MainWindow::createButton(const QString &str)
{
    QPushButton *btn = new QPushButton(str);
    btn->setMinimumSize(40, 40);
    // connect signal to slot.
    connect(btn, SIGNAL(clicked()), SLOT(slotButtonClicked()));
    return btn;
}

void MainWindow::calculate()
{
    double fOperandSecond = m_stk.pop().toDouble();	// get from stack the second operand.
    QString operation = m_stk.pop();				// get from stack the operator.
    double fOperandFirst = m_stk.pop().toDouble();	// get from stack the first operand.
    double fResult = 0;

    if(operation == "-")
        fResult = fOperandFirst - fOperandSecond;

    if(operation == "+")
        fResult = fOperandFirst + fOperandSecond;

    if(operation == "/")
        fResult = fOperandFirst / fOperandSecond;

    if(operation == "*")
        fResult = fOperandFirst * fOperandSecond;

    m_plcd->display(fResult);
}

void MainWindow::slotButtonClicked()
{
    //	Modify the signal from the sender to the text.
    QString str = (qobject_cast<QPushButton*>(sender()))->text();


    if ( str == "CE")
    {
        m_stk.clear();
        m_strDisplay = "";
        m_plcd->display("0");
        return;
    }

    //	If pressed a dot or the digit.
    if (str.contains(QRegExp("[0-9]")))
    {
        m_strDisplay += str;
        m_plcd->display(m_strDisplay.toDouble());
    }
    else if (str == ".")
    {
        m_strDisplay += str;
        m_plcd->display(m_strDisplay);
    }
    else //	Pressed operation button.
    {
    //	If stack keeps two or more items.
    //  place the digit from the display on to the stack
    //  and start the calculation.
    //  After the calculation clear the stack and put there the result.
    //  The equality operation does not put on the stack.
    //  place the digit from the display on to the stack
    //  and start the calculation.
    //  After the calculation clear the stack and put there the result.
    //	The equality operation does not put on the stack.
        if (m_stk.count() >= 2)
        {
            m_stk.push(QString().setNum(m_plcd->value()));
            calculate();
            m_stk.clear();
            m_stk.push(QString().setNum(m_plcd->value()));

            if (str != "=")
                m_stk.push(str);
        }
        else
        {
            //	Otherwise, put displayed digit and operation on the stack.
            m_stk.push(QString().setNum(m_plcd->value()));
            m_stk.push(str);
            m_strDisplay = "";
        }
    }

}

