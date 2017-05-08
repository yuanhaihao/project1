#include "drawer.h"
#include "ui_drawer.h"
#include <QTextCodec>


static QTextCodec * codec = QTextCodec::codecForName("GBK");
#define CODECGBK(x) codec->toUnicode(x)


Drawer::Drawer(QWidget *parent,Qt::WindowFlags f) :
    QToolBox(parent,f),
    ui(new Ui::Drawer)
{
//    ui->setupUi(this);

    setWindowTitle(CODECGBK("My QQ"));  //设置主窗体的标题
    toolBtn1_1 = new QToolButton;    //创建一个QToolButton类实例，分别对应于抽屉中的每一个按钮
    toolBtn1_1->setText(CODECGBK("王晨光"));  //设置按钮的文字
    toolBtn1_1->setIcon(QPixmap("11.jpg"));   //设置按钮的图标
    toolBtn1_1->setIconSize(QPixmap("11.jpg").size());  //设置按钮的大小，本例将其设置为与图标的大小相同
    toolBtn1_1->setAutoRaise(true);  //当鼠标离开时，按钮自动恢复为弹起状态
    toolBtn1_1->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);  /*设置按钮的ToolButtonStyle属性。ToolButtonStyle属性主要用来
   描述按钮的文字和图标的显示方式  Qt：：ToolbuttonIconOnly：只显示图标  Qt：：ToolButtonTextOnly：只显示文字   Qt：：ToolButtonTextBesideIcon：
文字显示在图标旁边   Qt：：ToolButtonTextUnderIcon：文字显示在图标下面  Qt：：ToolButtonFollowStyle：遵循Style标准*/
    toolBtn1_2 = new QToolButton;
    toolBtn1_2->setText(CODECGBK("刘攀"));
    toolBtn1_2->setIcon(QPixmap("12.jpg"));
    toolBtn1_2->setIconSize(QPixmap("12.jpg").size());
//    toolBtn1_2->resize(width(),height());
    toolBtn1_2->setAutoRaise(true);
    toolBtn1_2->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    toolBtn1_3 = new QToolButton;
    toolBtn1_3->setText(CODECGBK("王红星"));
    toolBtn1_3->setIcon(QPixmap("13.jpg"));
    toolBtn1_3->setIconSize(QPixmap("11.jpg").size());
    toolBtn1_3->setAutoRaise(true);
    toolBtn1_3->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    toolBtn1_4 = new QToolButton;
    toolBtn1_4->setText(CODECGBK("袁海浩"));
    toolBtn1_4->setIcon(QPixmap("14.jpg"));
    toolBtn1_4->setIconSize(QPixmap("14.jpg").size());
    toolBtn1_4->setAutoRaise(true);
    toolBtn1_4->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    toolBtn1_5 = new QToolButton;
    toolBtn1_5->setText(CODECGBK("陈新宇"));
    toolBtn1_5->setIcon(QPixmap("15.jpg"));
    toolBtn1_5->setIconSize(QPixmap("15.jpg").size());
    toolBtn1_5->setAutoRaise(true);
    toolBtn1_5->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    QGroupBox *groupBox1 = new QGroupBox;  //创建一个QGroupBox类实例，在本例中对应每一个抽屉
    QVBoxLayout *layout1 = new QVBoxLayout(groupBox1); //创建一个QVBoxLayout类实例，用来设置抽屉内的各个按钮布局
    layout1->setMargin(10);  //布局中各窗体的显示问题
    layout1->setAlignment(Qt::AlignHCenter); //布局中各窗体的显示位置
    //加入抽屉内的各个按钮
    layout1->addWidget(toolBtn1_1);
    layout1->addWidget(toolBtn1_2);
    layout1->addWidget(toolBtn1_3);
    layout1->addWidget(toolBtn1_4);
    layout1->addWidget(toolBtn1_5);
    //插入一个占位符
    layout1->addStretch();   //在按钮之后插入一个占位符，使得所有按钮能够靠上对齐，并且在整个抽屉大小发生改变时保证按钮的大小不发生变化
    toolBtn2_1 = new QToolButton;
    toolBtn2_1->setText(CODECGBK("小王"));
    toolBtn2_1->setIcon(QPixmap("16.jpg"));
    toolBtn2_1->setIconSize(QPixmap("16.jpg").size());
    toolBtn2_1->setAutoRaise(true);
    toolBtn2_1->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    toolBtn2_2 = new QToolButton;
    toolBtn2_2->setText(CODECGBK("小张"));
    toolBtn2_2->setIcon(QPixmap("17.jpg"));
    toolBtn2_2->setIconSize(QPixmap("17.jpg").size());
    toolBtn2_2->setAutoRaise(true);
    toolBtn2_2->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    QGroupBox *groupBox2 = new QGroupBox;
    QVBoxLayout *layout2 = new QVBoxLayout(groupBox2);
    layout2->setMargin(10);
    layout2->setAlignment(Qt::AlignHCenter);
    layout2->addWidget(toolBtn2_1);
    layout2->addWidget(toolBtn2_2);

    toolBtn3_1 = new QToolButton;
    toolBtn3_1->setText(CODECGBK("小陈"));
    toolBtn3_1->setIcon(QPixmap("18.jpg"));
    toolBtn3_1->setIconSize(QPixmap("18.jpg").size());
    toolBtn3_1->setAutoRaise(true);
    toolBtn3_1->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    toolBtn3_2 = new QToolButton;
    toolBtn3_2->setText(CODECGBK("小李"));
    toolBtn3_2->setIcon(QPixmap("19.jpg"));
    toolBtn3_2->setIconSize(QPixmap("19.jpg").size());
    toolBtn3_2->setAutoRaise(true);
    toolBtn3_2->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    QGroupBox *groupBox3 = new QGroupBox;
    QVBoxLayout *layout3 = new QVBoxLayout(groupBox3);
    layout3->setMargin(10);
    layout3->setAlignment(Qt::AlignHCenter);
    layout3->addWidget(toolBtn3_1);
    layout3->addWidget(toolBtn3_2);
    //将准备好的抽屉插入ToolBox中
    this->addItem((QWidget*)groupBox1,CODECGBK("我的好友"));
    this->addItem((QWidget*)groupBox2,CODECGBK("陌生人"));
    this->addItem((QWidget*)groupBox3,CODECGBK("黑名单"));
}

Drawer::~Drawer()
{
    delete ui;
}
