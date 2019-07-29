#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void addSlot(); // это созданный нами слот для операции +
    void subtractSlot(); // это созданный нами слот для операции -
    void multiplySlot(); // это созданный нами слот для операции *
    void divideSlot(); // это созданный нами слот для операции /
    void equallySlot(); // это созданный нами слот для операции =

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
