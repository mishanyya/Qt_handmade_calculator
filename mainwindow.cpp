#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(addSlot()));//\+
   connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(subtractSlot()));//\-
   connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(multiplySlot()));//\*
   connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(divideSlot()));//\/
   connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(equallySlot()));//\=
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
 Алгоритм работы:
1)вводим число,
2)нажимаем на знак, это число и знак сохраняются,
3)вводим другое число,
4)нажимаем знак равно эти два числа высчитываются с учетом знака,
5)при этом должны вводиться только цифры и точка

objectName:
lineEdit     - это поле для ввода чисел
pushButton   - это знак +
pushButton_2 - это знак -
pushButton_3 - это знак *
pushButton_4 - это знак /
pushButton_5 - это знак =

Переменные:
первое значение - firstvalue
второе значение - secondvalue
результат значение - resultvalue
для арифметических знаков - sign
для знака равенства - signequally

QString объект для работы с данными
lineEdit,lineEdit_2 и другие значения- это objectName для каждого из этих элементов
*/

float firstvalue;//первое введенное значение
QString sign;//знак арифметического действия
float res;//результат

void MainWindow::addSlot()
{
     ::firstvalue= ui->lineEdit->text().toFloat(); // получаем первое значение QLineEdit
   ::sign = ui->pushButton->text(); // получаем строку из кнопки pushButton +

}

void MainWindow::subtractSlot()
{
     ::firstvalue = ui->lineEdit->text().toFloat(); // получаем первое значение QLineEdit
   ::sign = ui->pushButton_2->text(); // получаем строку из кнопки pushButton -

}

void MainWindow::multiplySlot()
{
     ::firstvalue = ui->lineEdit->text().toFloat(); // получаем первое значение QLineEdit
   ::sign = ui->pushButton_3->text(); // получаем строку из кнопки pushButton *

}

void MainWindow::divideSlot()
{
     ::firstvalue = ui->lineEdit->text().toFloat(); // получаем первое значение QLineEdit
   ::sign = ui->pushButton_4->text(); // получаем строку из кнопки pushButton /

}

void MainWindow::equallySlot()
{
    float res;
    float secondvalue = ui->lineEdit->text().toFloat(); // получаем второе значение QLineEdit

   //QString res= (::firstvalue)+(::sign)+(secondvalue);
    //QString signequally = ui->pushButton_5->text(); // получаем строку из кнопки pushButton
    //действия взависимости от знака:

    //str.setNum(::sign);//переводит численное значение в текст

    if(::sign=='+') {
        res=(::firstvalue)+secondvalue;
    }
    else if (::sign=='-') {
        res=(::firstvalue)-secondvalue;
    }
    else if (::sign=='*') {
        res=(::firstvalue)*secondvalue;
    }
    else if (::sign=='/') {
        res=(::firstvalue)/secondvalue;
    }

   //ui->label->setNum(res); // получаем строку из кнопки pushButton

   ui->lineEdit->setText(QString::number(res));


}


