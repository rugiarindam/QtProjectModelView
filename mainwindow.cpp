#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QGridLayout>
#include<QTimer>
#include<QtGlobal>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QGridLayout *gl = new QGridLayout;

   // QStringList lst;
    lst<<"Apple"<<"Sony"<<"Google";

    for(int i=1;i<=2;i++)
    {
       DisplayWidget *dw=new DisplayWidget(this);
       gl->addWidget(dw,i,1,1,10+i);
       dw->setList(lst);
       widgetMap[i]=dw;
   }

    ui->centralWidget->setLayout(gl);

    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(onTimeout()));
    timer->start(1000);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onTimeout()
{

    for(int i=0;i<3;++i)
    {
    int number=255;
    int randomValue = qrand() % number;// Creating random number between 0 and 255

    // https://stackoverflow.com/questions/2618414/convert-an-int-to-a-qstring-with-zero-padding-leading-zeroes
    lst[i]=QString("Param%1:%2").arg(i).arg(randomValue,3, 10, QChar('0'));//yourNumber, 5, 10, QChar('0')
    }
    widgetMap[1]->setList(lst);// Writing in first widget
}
