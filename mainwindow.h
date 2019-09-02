#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<displaywidget.h>
#include<QMap>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void onTimeout();

private:
    Ui::MainWindow *ui;
    DisplayWidget*dw;
    QMap<int,DisplayWidget*> widgetMap;
    QStringList lst;
};

#endif // MAINWINDOW_H
