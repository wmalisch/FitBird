#include "mainmenu.h"

#include <QApplication>
#include "facade.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainMenu w;

    //Load data stored
    Facade::instance()->load();

    w.show();
    int r = a.exec();
    Facade::instance()->save();
    return r;
}
