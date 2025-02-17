#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->counter->setReadOnly(true);
    ui->counter->setText(QString::number(count));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_countButton_clicked()
{
    count++;
    ui->counter->setText(QString::number(count));
}


void MainWindow::on_resetButton_clicked()
{
    count = 0;
    ui->counter->setText(QString::number(count));
}

