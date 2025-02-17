#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->B0, QPushButton::clicked, this, on_number_clicked);
    QObject::connect(ui->B1, QPushButton::clicked, this, on_number_clicked);
    QObject::connect(ui->B2, QPushButton::clicked, this, on_number_clicked);
    QObject::connect(ui->B3, QPushButton::clicked, this, on_number_clicked);
    QObject::connect(ui->B4, QPushButton::clicked, this, on_number_clicked);
    QObject::connect(ui->B5, QPushButton::clicked, this, on_number_clicked);
    QObject::connect(ui->B6, QPushButton::clicked, this, on_number_clicked);
    QObject::connect(ui->B7, QPushButton::clicked, this, on_number_clicked);
    QObject::connect(ui->B8, QPushButton::clicked, this, on_number_clicked);
    QObject::connect(ui->B9, QPushButton::clicked, this, on_number_clicked);

    QObject::connect(ui->add0, QPushButton::clicked, this, on_operator_clicked);
    QObject::connect(ui->divide2, QPushButton::clicked, this, on_operator_clicked);
    QObject::connect(ui->multiply3, QPushButton::clicked, this, on_operator_clicked);
    QObject::connect(ui->subtract1, QPushButton::clicked, this, on_operator_clicked);

    QObject::connect(ui->number0, QLineEdit::textChanged, this, on_text_changed);
    QObject::connect(ui->number1, QLineEdit::textChanged, this, on_text_changed);

    QObject::connect(ui->number0, QLineEdit::cursorPositionChanged, this, on_text_focused);
    QObject::connect(ui->number1, QLineEdit::cursorPositionChanged, this, on_text_focused);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_number_clicked(){
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    QString name = button->objectName();

    int number = name.last(1).toInt();
    numbers[curNumber] *= 10;
    numbers[curNumber] += number;
    switch (curNumber){
        case 0:
            ui->number0->setText(QString::number(numbers[curNumber]));
            ui->number0->setCursorPosition(0);
            break;
        default:
            ui->number1->setText(QString::number(numbers[curNumber]));
            ui->number1->setCursorPosition(0);
    }
    qDebug() << number;
}

void MainWindow::on_operator_clicked(){
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    cOperator =  button->objectName().last(1).toInt();
    if (curNumber < 1){
        curNumber++;
    }
}

void MainWindow::on_text_changed(){
    QLineEdit* text = qobject_cast<QLineEdit*>(sender());
    int index = text->objectName().last(1).toInt();
    qDebug() << index;
    curNumber = index;
    numbers[index] = text->text().toInt();
}

void MainWindow::on_text_focused(){
    QLineEdit* text = qobject_cast<QLineEdit*>(sender());
    int index = text->objectName().last(1).toInt();
    qDebug() << index;
    curNumber = index;
}

void MainWindow::on_pushButton_8_clicked()
{
    numbers[0] = 0;
    numbers[1] = 0;
    ui->number0->clear();
    ui->number1->clear();
    ui->resultNumber->clear();
    curNumber = 0;
}


void MainWindow::on_pushButton_15_clicked()
{
    float result;
    switch(cOperator){
    case 0:
        result = float(numbers[0])+float(numbers[1]);
        break;
    case 1:
        result = float(numbers[0])-float(numbers[1]);
        break;
    case 2:
        result = float(numbers[0])/float(numbers[1]);
        break;
    case 3:
        result = float(numbers[0])*float(numbers[1]);
        break;
    }
    ui->resultNumber->setText(QString::number(result));
}

