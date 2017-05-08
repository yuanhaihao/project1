#include "msgboxdlg.h"
#include <QTextCodec>


static QTextCodec * codec = QTextCodec::codecForName("GBK");
#define CODECGBK(x) codec->toUnicode(x)

MsgBoxDlg::MsgBoxDlg(QWidget *parent)
    :QDialog(parent)
{
    setWindowTitle(CODECGBK("标准消息对话框"));
    label = new QLabel;
    label->setText(CODECGBK("请选择一种消息框"));

    questionBtn = new QPushButton;
    questionBtn->setText(CODECGBK("QuestionMsg"));
    informationBtn = new QPushButton;
    informationBtn->setText(CODECGBK("InformationMsg"));
    warningBtn = new QPushButton;
    warningBtn->setText(CODECGBK("WarningMsg"));
    criticalBtn = new QPushButton;
    criticalBtn->setText(CODECGBK("CriticalMsg"));
    aboutBtn = new QPushButton;
    aboutBtn->setText(CODECGBK("AboutMsg"));
    aboutQtBtn = new QPushButton;
    aboutQtBtn->setText(CODECGBK("AboutQtMsg"));
    //布局
    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(label,0,0,1,2);
    mainLayout->addWidget(questionBtn,1,0);
    mainLayout->addWidget(informationBtn,1,1);
    mainLayout->addWidget(warningBtn,2,0);
    mainLayout->addWidget(criticalBtn,2,1);
    mainLayout->addWidget(aboutBtn,3,0);
    mainLayout->addWidget(aboutQtBtn,3,1);
    //事件关联
    connect(questionBtn,SIGNAL(clicked()),this,SLOT(showQuestionMsg()));
    connect(informationBtn,SIGNAL(clicked()),this,SLOT(showInformationMsg()));
    connect(warningBtn,SIGNAL(clicked()),this,SLOT(showWarningMsg()));
    connect(criticalBtn,SIGNAL(clicked()),this,SLOT(showCriticalMsg()));
    connect(aboutBtn,SIGNAL(clicked()),this,SLOT(showAboutMsg()));
    connect(aboutQtBtn,SIGNAL(clicked()),this,SLOT(showAboutQtMsg()));
}

void MsgBoxDlg::showAboutQtMsg()
{
    label->setText(CODECGBK("About Qt Message Box"));
    QMessageBox::aboutQt(this,CODECGBK("About Qt 消息框"));
    return;
}

void MsgBoxDlg::showAboutMsg()
{
    label->setText(CODECGBK("About Message Box"));
    QMessageBox::about(this,CODECGBK("About 消息框"),CODECGBK("这是一个About消息测试框！"));
    return;
}

void MsgBoxDlg::showCriticalMsg()
{
    label->setText(tr("Critical Message Box"));
    QMessageBox::critical(this,CODECGBK("Critical 消息框"),CODECGBK("这是一个Critical消息框测试！"));
    return;
}

void MsgBoxDlg::showWarningMsg()
{
    label->setText(CODECGBK("Warning Message Box"));
    switch(QMessageBox::warning(this,CODECGBK("Warning 消息框"),CODECGBK("您修改的内容还未保存，是否保存对文档的修改？"),QMessageBox::Save|QMessageBox::Discard|QMessageBox::Cancel,QMessageBox::Save))
    {
        case QMessageBox::Save :
        {
            label->setText(CODECGBK("Warning button/Save"));
            break;
        }
        case QMessageBox::Discard :
        {
            label->setText(CODECGBK("Warning button/Discard"));
            break;
        }
        case QMessageBox::Cancel :
        {
            label->setText(CODECGBK("Warning button/Cancel"));
        }
    }

}

void MsgBoxDlg::showInformationMsg()
{
    label->setText(CODECGBK("Information Message Box"));
    QMessageBox::information(this,CODECGBK("Information 消息框"),CODECGBK("这是Information消息框测试，欢迎您！"));
    return;
}

void MsgBoxDlg::showQuestionMsg()
{
    label->setText(CODECGBK("Question Message Box"));
    switch(QMessageBox::question(this,CODECGBK("Question消息框"),CODECGBK("您现在已经修改完成，是否要结束程序？"),QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok))
    {
        case QMessageBox::Ok :
        {
            label->setText("Question button/OK");
            break;
        }
        case QMessageBox::Cancel :
        {
            label->setText("Question button/Cancel");
            break;
        }
        default:
            break;
    }
    return;
}
