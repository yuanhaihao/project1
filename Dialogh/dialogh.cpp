#include "dialogh.h"
#include "ui_dialogh.h"
#include <QTextCodec>


static QTextCodec * codec = QTextCodec::codecForName("GBK");
#define CODECGBK(x) codec->toUnicode(x)


dialogh::dialogh(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialogh)
{
//    ui->setupUi(this);
    setWindowTitle(CODECGBK("各种标准对话框"));
    fileBtn = new QPushButton;  //各个控件对象的初始化
    fileBtn->setText(CODECGBK("文件标准对话框"));
    fileLineEdit = new QLineEdit;  //用来显示选择的文件名
    //添加布局管理
    mainLayout = new QGridLayout(this);//布局设计
    mainLayout->addWidget(fileBtn,0,0);
    mainLayout->addWidget(fileLineEdit,0,1);
    //添加事件关联
    connect(fileBtn,SIGNAL(clicked()),this,SLOT(showFile()));
    //颜色
    colorBtn = new QPushButton;
    colorBtn->setText(CODECGBK("颜色标准对话框"));
    colorFrame = new QFrame;
    colorFrame->setFrameShape(QFrame::Box);
    colorFrame->setAutoFillBackground(true);
    //添加布局管理
    mainLayout->addWidget(colorBtn,1,0);
    mainLayout->addWidget(colorFrame,1,1);
    //添加关联事件
    connect(colorBtn,SIGNAL(clicked()),this,SLOT(showColor()));
    //字体
    fontBtn = new QPushButton;
    fontBtn->setText(CODECGBK("字体标准对话框"));
    fontLineEdit = new QLineEdit;
    fontLineEdit->setText(CODECGBK("欢迎"));
    //布局管理
    mainLayout->addWidget(fontBtn,2,0);//布局设计
    mainLayout->addWidget(fontLineEdit,2,1);
    //添加关联事件
    connect(fontBtn,SIGNAL(clicked()),this,SLOT(showFont()));
    //标准输入对话框
    sprintBtn = new QPushButton;
    sprintBtn->setText(CODECGBK("标准输入对话框"));

    mainLayout->addWidget(sprintBtn,3,0);

    connect(sprintBtn,SIGNAL(clicked()),this,SLOT(showSprint()));
    //消息框
    msgbox = new QPushButton;
    msgbox->setText(CODECGBK("标准消息框"));
    mainLayout->addWidget(msgbox,3,1);
    connect(msgbox,SIGNAL(clicked()),this,SLOT(showMsgBox()));

}

void dialogh::showMsgBox()
{
    msgboxdlg = new MsgBoxDlg(this);
    msgboxdlg->show();
}

void dialogh::showSprint()
{
    input = new inputdlg(this);
    input->show();
}

void dialogh::showFont()
{
    bool ok;
    QFont f = QFontDialog::getFont(&ok);
    if(ok)
        fontLineEdit->setFont(f);
}

void dialogh::showColor()
{
    QColor c = QColorDialog::getColor(Qt::blue);
    if(c.isValid())
        colorFrame->setPalette(QPalette(c));
}

void dialogh::showFile()
{
    QString s = QFileDialog::getOpenFileName(this,"open file dialog","/","C++ file(*.cpp)::C file(*.c)::Head file(*.h)");
    fileLineEdit->setText(s);
}

dialogh::~dialogh()
{
    delete ui;
}
