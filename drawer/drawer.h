#ifndef DRAWER_H
#define DRAWER_H

#include <QMainWindow>
#include <QToolButton>
#include <QToolBox>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QPixmap>

namespace Ui {
class Drawer;
}

class Drawer : public QToolBox
{
    Q_OBJECT

public:
    explicit Drawer(QWidget *parent = 0,Qt::WindowFlags f = 0);
    ~Drawer();

private:
    Ui::Drawer *ui;
    QToolButton *toolBtn1_1;
    QToolButton *toolBtn1_2;
    QToolButton *toolBtn1_3;
    QToolButton *toolBtn1_4;
    QToolButton *toolBtn1_5;

    QToolButton *toolBtn2_1;
    QToolButton *toolBtn2_2;

    QToolButton *toolBtn3_1;
    QToolButton *toolBtn3_2;
};

#endif // DRAWER_H
