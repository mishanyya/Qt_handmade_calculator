#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QAbstractButton>

#include <QPushButton>
#include <QWidget>
#include <QLabel>

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
    void addSlot(); // это созданный нами слот для +
    void subtractSlot(); // это созданный нами слот для -
    void multiplySlot(); // это созданный нами слот для *
    void divideSlot(); // это созданный нами слот для /
    void equallySlot(); // это созданный нами слот для =


private:
    Ui::MainWindow *ui;
};




#endif // MAINWINDOW_H
