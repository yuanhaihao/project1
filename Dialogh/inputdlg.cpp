#include "inputdlg.h"
#include <QTextCodec>


static QTextCodec * codec = QTextCodec::codecForName("GBK");
#define CODECGBK(x) codec->toUnicode(x)

inputdlg::inputdlg(QWidget *parent)
    :QDialog(parent)
{
    //标准输入对话框
    setWindowTitle(CODECGBK("标准输入对话框"));
    nameLabel1 = new QLabel;
    nameLabel1->setText(CODECGBK("姓名："));
    nameLabel2 = new QLabel;
    nameLabel2->setText(CODECGBK("王晨光"));
    nameLabel2->setFrameStyle(QFrame::Panel|QFrame::Sunken);
    nameBtn = new QPushButton;
    nameBtn->setText(CODECGBK("修改姓名"));

    sexLabel1 = new QLabel;
    sexLabel1->setText(CODECGBK("性别："));
    sexLabel2 = new QLabel;
    sexLabel2->setText(CODECGBK("男"));
    sexLabel2->setFrameStyle(QFrame::Panel|QFrame::Sunken);
    sexBtn = new QPushButton;
    sexBtn->setText(CODECGBK("修改性别"));

    ageLabel1 = new QLabel;
    ageLabel1->setText(CODECGBK("年龄："));
    ageLabel2 = new QLabel;
    ageLabel2->setText(CODECGBK("25"));
    ageLabel2->setFrameStyle(QFrame::Panel|QFrame::Sunken);
    ageBtn = new QPushButton;
    ageBtn->setText(CODECGBK("修改年龄"));

    scoreLabel1 = new QLabel;
    scoreLabel1->setText(CODECGBK("成绩："));
    scoreLabel2 = new QLabel;
    scoreLabel2->setText(CODECGBK("85"));
    scoreLabel2->setFrameStyle(QFrame::Panel|QFrame::Sunken);
    scoreBtn = new QPushButton;
    scoreBtn->setText(CODECGBK("修改成绩"));

    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(nameLabel1,0,0);
    mainLayout->addWidget(nameLabel2,0,1);
    mainLayout->addWidget(nameBtn,0,2);
    mainLayout->addWidget(sexLabel1,1,0);
    mainLayout->addWidget(sexLabel2,1,1);
    mainLayout->addWidget(sexBtn,1,2);
    mainLayout->addWidget(ageLabel1,2,0);
    mainLayout->addWidget(ageLabel2,2,1);
    mainLayout->addWidget(ageBtn,2,2);
    mainLayout->addWidget(scoreLabel1,3,0);
    mainLayout->addWidget(scoreLabel2,3,1);
    mainLayout->addWidget(scoreBtn,3,2);

    mainLayout->setMargin(15);
    mainLayout->setSpacing(10);

    connect(nameBtn,SIGNAL(clicked()),this,SLOT(ChangeName()));
    connect(sexBtn,SIGNAL(clicked()),this,SLOT(ChangeSex()));
    connect(ageBtn,SIGNAL(clicked()),this,SLOT(ChangeAge()));
    connect(scoreBtn,SIGNAL(clicked()),this,SLOT(ChangeScore()));
}

void inputdlg::ChangeScore()
{
    bool ok;
    double score = QInputDialog::getDouble(this,CODECGBK("标准double类型输入对话框"),CODECGBK("请输入成绩："),scoreLabel2->text().toDouble(&ok),0,100,1,&ok);
    if(ok)
        scoreLabel2->setText(QString(CODECGBK("%1")).arg(score));
}

void inputdlg::ChangeAge()
{
    bool ok;
    int age = QInputDialog::getInt(this,CODECGBK("标准int类型输入对话框"),CODECGBK("请输入年龄："),ageLabel2->text().toInt(&ok),0,100,1,&ok);
    if(ok)
        ageLabel2->setText(QString(CODECGBK("%1")).arg(age));
}

void inputdlg::ChangeSex()
{
    QStringList SexItems;
    SexItems << CODECGBK("男") << CODECGBK("女");
    bool ok;
    QString SexItem = QInputDialog::getItem(this,CODECGBK("标准条目选择对话框"),CODECGBK("请选择性别："),SexItems,0,false,&ok);
    if(ok && !SexItem.isEmpty())
        sexLabel2->setText(SexItem);
}

void inputdlg::ChangeName()
{
    bool ok;
    QString text = QInputDialog::getText(this,CODECGBK("标准字符串输入对话框"),CODECGBK("请输入姓名："),QLineEdit::Normal,nameLabel2->text(),&ok);
    if(ok && !text.isEmpty())
        nameLabel2->setText(text);
}
