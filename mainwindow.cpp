#include "mainwindow.h"
#include "ui_mainwindow.h"
class SecondWindow;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dialog.show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
