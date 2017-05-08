#include "dialogh.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    dialogh w;
    w.show();

    return a.exec();
}
