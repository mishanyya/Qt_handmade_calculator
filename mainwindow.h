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

    void forAllMovieSlot(); // это слот для всех операций
    void forTextEditResultSlot(); // это слот для получения промежуточного результата
    void forTextClean(); // это слот для очистки текстового поля
    void forTextReset(); // это слот для обнуления данных
    void forSymbolEnter(); // это слот для ввода цифр в текстовое поле


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
