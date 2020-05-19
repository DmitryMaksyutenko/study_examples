#include "widget.h"

Widget::Widget(QWidget *parent)
  : QWidget(parent)
{
  setGeometry(600, 300, 500, 700);
  mTextArea.setParent(this);
  mTextArea.setGeometry(0, 0, width(), height());
  mTextArea.setText("Default text!");
}

Widget::~Widget()
{
}

void Widget::slotAddedToClipBoard()
{
    mTextArea.clear();
    mTextArea.setText("SOMETHING WAS ADDED TO CLIPBOARD!");
}

