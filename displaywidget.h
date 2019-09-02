#ifndef DISPLAYWIDGET_H
#define DISPLAYWIDGET_H

#include <QWidget>
#include<QStringListModel>
namespace Ui {
class DisplayWidget;
}

class DisplayWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DisplayWidget(QWidget *parent = 0);
    ~DisplayWidget();
    void setList(QStringList & lst);

private:
    Ui::DisplayWidget *ui;
    QStringListModel *model;
};

#endif // DISPLAYWIDGET_H
