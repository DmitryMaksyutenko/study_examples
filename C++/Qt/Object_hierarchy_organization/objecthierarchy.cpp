#include "objecthierarchy.h"
#include "ui_objecthierarchy.h"

ObjectHierarchy::ObjectHierarchy(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ObjectHierarchy)
{
    ui->setupUi(this);
}

ObjectHierarchy::~ObjectHierarchy()
{
    delete ui;
}

