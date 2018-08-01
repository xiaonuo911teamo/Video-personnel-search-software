#include "findpeoplewindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    findPeopleWindow w;
    w.show();

    return a.exec();
}
