#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QApplication>  //подключает класс для работы с QApplication, добавляется обязательно !!!

//#include <QAbstractButton>//
//#include <QWidget>        //
//#include <QPushButton>      //подключает класс для работы с кнопками, добавляется при необходимости!
//#include <QProgressBar>     //подключает класс для работы с QProgressBar, добавляется при необходимости!
//#include <QSlider>          //подключает класс для работы с QSlider, добавляется при необходимости!
//#include <QLineEdit>        //подключает класс для работы с полем для ввода текста, добавляется при необходимости!
//#include <QLabel>           //подключает класс для работы с полем для показа какой-либо информации, добавляется при необходимости!
//#include <QValidator>       //подключает класс для фильтра значений, добавляется при необходимости!
//#include <QDoubleValidator> //подключает класс для фильтра числовых значений типа double, добавляется при необходимости!
#include <QRegExpValidator>   //подключает класс для фильтра значений через регулярные выражения, добавляется при необходимости!
//#include <QtMath>           //подключает класс для математических функций





MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(addSlot()));         //для сложения
   connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(subtractSlot()));  //для вычитания
   connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(multiplySlot()));  //для умножения
   connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(divideSlot()));    //для деления
   connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(equallySlot()));   //для получения результата

   //сделать поле ввода  активным при запуске программы
ui->lineEdit->setFocus();
//разрешен только ввод чисел в поле ввода lineEdit
   QRegExp rx("-?\\d+([.]\\d{0,})?");//
   QValidator *my_Validator = new QRegExpValidator(rx,this);//создание нового объекта QValidator
   ui->lineEdit->setValidator(my_Validator);//подключение регулярного выражения к текстовому полю lineEdit

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

Требования:
1)при этом должны вводиться только цифры и точка
2)поле ввода становится активным перед вводом каждого числа

3!нельзя делить на ноль
4!возможность ввода знаков с клавиатуры
5!добавить другие функции
6!если стоит другая раскладка клавиатуры, сообщить об этом

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
   ::firstvalue= ui->lineEdit->text().toFloat(); // получаем первое значение QLineEdit
   ::sign = ui->pushButton->text(); // получаем строку из кнопки pushButton +
ui->lineEdit->setFocus();//сделать поле ввода  активным
ui->lineEdit->setText(nullptr);//удалить данные из поля ввода
}

void MainWindow::subtractSlot()
{   
   ::firstvalue = ui->lineEdit->text().toFloat(); // получаем первое значение QLineEdit
   ::sign = ui->pushButton_2->text(); // получаем строку из кнопки pushButton -
    ui->lineEdit->setFocus();//сделать поле ввода  активным
    ui->lineEdit->setText(nullptr);//удалить данные из поля ввода
}

void MainWindow::multiplySlot()
{
    ::firstvalue = ui->lineEdit->text().toFloat(); // получаем первое значение QLineEdit
   ::sign = ui->pushButton_3->text(); // получаем строку из кнопки pushButton *
    ui->lineEdit->setFocus();//сделать поле ввода  активным
    ui->lineEdit->setText(nullptr);//удалить данные из поля ввода
}

void MainWindow::divideSlot()
{
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
        ::firstvalue=secondvalue=0;//обнуление переменных
    }
    else if (::sign=='-') {
        res=(::firstvalue)-secondvalue;
        ::firstvalue=secondvalue=0;//обнуление переменных
    }
    else if (::sign=='*') {
        res=(::firstvalue)*secondvalue;
        ::firstvalue=secondvalue=0;//обнуление переменных
    }
    else if (::sign=='/') {
         res=(::firstvalue)/secondvalue;
        ::firstvalue=secondvalue=0;//обнуление переменных
     }
    else res=0;

   ui->lineEdit->setText(QString::number(res));

}


