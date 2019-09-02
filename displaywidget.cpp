#include "displaywidget.h"
#include "ui_displaywidget.h"

DisplayWidget::DisplayWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DisplayWidget)
{
    ui->setupUi(this);
    model = new QStringListModel(this);
    ui->listView->setFont(QFont("Time",20,90));
    ui->listView->setStyleSheet(QString("color:#ffffff;background-color:#646464"));
}

DisplayWidget::~DisplayWidget()
{
    delete ui;
}

void DisplayWidget::setList(QStringList & lst)
{
    model->setStringList(lst);
    ui->listView->setModel(model);
}
