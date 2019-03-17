#include "mainwindow.h"
#include <QApplication>
#include "login.h"
#include"iostream"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Login l;
    l.show();
    QObject::connect(&l,SIGNAL(showmain()),&w,SLOT(receivelogin()));
    return a.exec();
}
