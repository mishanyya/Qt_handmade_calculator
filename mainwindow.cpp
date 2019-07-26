#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QApplication>  //подключает класс для работы с QApplication, добавляется обязательно !!!

#include <QAbstractButton>//
#include <QWidget>        //
#include <QPushButton>      //подключает класс для работы с кнопками, добавляется при необходимости!
#include <QProgressBar>     //подключает класс для работы с QProgressBar, добавляется при необходимости!
#include <QSlider>          //подключает класс для работы с QSlider, добавляется при необходимости!
#include <QLineEdit>        //подключает класс для работы с полем для ввода текста, добавляется при необходимости!
#include <QLabel>           //подключает класс для работы с полем для показа какой-либо информации, добавляется при необходимости!
#include <QValidator>       //подключает класс для фильтра значений, добавляется при необходимости!
#include <QDoubleValidator> //подключает класс для фильтра числовых значений типа double, добавляется при необходимости!
#include <QRegExpValidator> //подключает класс для фильтра значений через регулярные выражения, добавляется при необходимости!






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


//разрешен только ввод чисел в поле ввода lineEdit
   QRegExp rx("-?\\d{1,}");//установка регулярного выражения rx("-?\\d{1,3}")
   QValidator *my_Validator = new QRegExpValidator(rx,this);//создание нового объекта QValidator
   ui->lineEdit->setValidator(my_Validator);//подключение регулярного выражения к текстовому полю lineEdit

   /*
d{1,3}-разрешен ввод только цифр, в количестве от одной до трех
d-разрешен ввод только одной цифры
d{1,}-разрешен ввод не менее одной цифры
d{,5}-разрешен ввод до пяти цифр
*/

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
6)поле ввода становится активным перед вводом каждого числа

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
результат - result
арифметические знаки - sign
*/

static float firstvalue;//первое введенное значение, пишется static, так как получает значение внутри другой функции
static QString sign;//знак арифметического действия, пишется static, так как получает значение внутри другой функции

void MainWindow::addSlot()
{
   ui->lineEdit->setFocus();//сделать поле ввода  активным
   ::firstvalue= ui->lineEdit->text().toFloat(); // получаем первое значение QLineEdit
   ::sign = ui->pushButton->text(); // получаем строку из кнопки pushButton +
ui->lineEdit->setFocus();//сделать поле ввода  активным
ui->lineEdit->setText(nullptr);//удалить данные из поля ввода
}

void MainWindow::subtractSlot()
{   

    ui->lineEdit->setFocus();//сделать поле ввода  активным
    ::firstvalue = ui->lineEdit->text().toFloat(); // получаем первое значение QLineEdit
   ::sign = ui->pushButton_2->text(); // получаем строку из кнопки pushButton -
    ui->lineEdit->setFocus();//сделать поле ввода  активным
    ui->lineEdit->setText(nullptr);//удалить данные из поля ввода
}

void MainWindow::multiplySlot()
{

    ui->lineEdit->setFocus();//сделать поле ввода  активным
    ::firstvalue = ui->lineEdit->text().toFloat(); // получаем первое значение QLineEdit
   ::sign = ui->pushButton_3->text(); // получаем строку из кнопки pushButton *
    ui->lineEdit->setFocus();//сделать поле ввода  активным
    ui->lineEdit->setText(nullptr);//удалить данные из поля ввода
}

void MainWindow::divideSlot()
{

    ui->lineEdit->setFocus();//сделать поле ввода  активным
    ::firstvalue = ui->lineEdit->text().toFloat(); // получаем первое значение QLineEdit
   ::sign = ui->pushButton_4->text(); // получаем строку из кнопки pushButton /
    ui->lineEdit->setFocus();//сделать поле ввода  активным
    ui->lineEdit->setText(nullptr);//удалить данные из поля ввода
}

void MainWindow::equallySlot()
{
    float secondvalue = ui->lineEdit->text().toFloat(); // получаем второе значение QLineEdit
    float res;//результат, пишется extern, так как получает значение внутри другой функции


    if(::sign=='+') {
        res=(::firstvalue)+secondvalue;
    }
    else if (::sign=='-') {
        res=(::firstvalue)-secondvalue;
    }
    else if (::sign=='*') {
        res=(::firstvalue)*secondvalue;
    }
    else/* if (::sign=='/')*/ {
        res=(::firstvalue)/secondvalue;
    }

   //ui->label->setNum(res); // получаем строку из кнопки pushButton

   ui->lineEdit->setText(QString::number(res));


}


