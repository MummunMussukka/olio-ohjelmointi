#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_number_clicked();
    void on_operator_clicked();
    void on_text_changed();
    void on_text_focused();

    void on_pushButton_8_clicked();

    void on_pushButton_15_clicked();

private:
    Ui::MainWindow *ui;
    int numbers[2] = {0, 0};
    int curNumber = 0;
    int cOperator;
};
#endif // MAINWINDOW_H
