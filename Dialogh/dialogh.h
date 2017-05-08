#ifndef DIALOGH_H
#define DIALOGH_H

#include <QMainWindow>
#include "inputdlg.h"
#include "msgboxdlg.h"
#include <QLineEdit>
#include <QGridLayout>
#include <QPushButton>
#include <QFileDialog>
#include <QFrame>
#include <QColorDialog>
#include <QDialog>
#include <QFontDialog>
#include <QInputDialog>
#include <QLabel>

namespace Ui {
class dialogh;
}

class dialogh : public QDialog
{
    Q_OBJECT

public:
    explicit dialogh(QWidget *parent = 0);
    ~dialogh();

private:
    Ui::dialogh *ui;
    QPushButton *fileBtn;
    QLineEdit *fileLineEdit;

    QPushButton *colorBtn;
    QFrame *colorFrame;
    QPushButton *fontBtn;
    QLineEdit *fontLineEdit;

    QPushButton *sprintBtn;

    QGridLayout *mainLayout;

    inputdlg *input;

    QPushButton *msgbox;
    MsgBoxDlg *msgboxdlg;


private slots:
    void showFile();
    void showColor();
    void showFont();
    void showSprint();
    void showMsgBox();
};

#endif // DIALOGH_H
