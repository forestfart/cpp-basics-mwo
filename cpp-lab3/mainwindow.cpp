#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this); //wywolanie funkcji setupUI
}

MainWindow::~MainWindow()
{
    delete ui; //zwolnienie pamieci
}
