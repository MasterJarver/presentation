#include "mainwindow.h"
#include <QApplication>
#include <dialog.h>
#include <QKeyEvent>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    return a.exec();
}
