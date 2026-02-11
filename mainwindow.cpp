#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setStyleSheet("QWidget { border: 1px solid red; }"); // debug border
}

MainWindow::~MainWindow()
{
    delete ui;
}
