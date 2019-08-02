#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QApplication>  //подключает класс для работы с QApplication, добавляется обязательно !!!

//#include <QAbstractButton>//
//#include <QWidget>        //
#include <QPushButton>      //подключает класс для работы с кнопками, добавляется при необходимости!
//#include <QProgressBar>     //подключает класс для работы с QProgressBar, добавляется при необходимости!
//#include <QSlider>          //подключает класс для работы с QSlider, добавляется при необходимости!
//#include <QLineEdit>        //подключает класс для работы с полем для ввода текста, добавляется при необходимости!
#include <QLabel>           //подключает класс для работы с полем для показа какой-либо информации, добавляется при необходимости!
//#include <QValidator>       //подключает класс для фильтра значений, добавляется при необходимости!
#include <QDoubleValidator> //подключает класс для фильтра числовых значений типа double, добавляется при необходимости!
#include <QRegExpValidator>   //подключает класс для фильтра значений через регулярные выражения, добавляется при необходимости!
//#include <QtMath>           //подключает класс для математических функций
#include <QKeyEvent>          //подключает класс для получения данных с клавиатуры
#include <QDebug>             //
#include <QTextEdit>        //подключает класс для работы с полем для ввода текста, добавляется при необходимости!


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->lineEdit, SIGNAL(editingFinished()), this, SLOT(forValueSlot()));//для сохранения значения после редактирования и нажатия любой кнопки
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(forAllMovieSlot()));         //для арифметической операции
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(forAllMovieSlot()));  //для арифметической операции
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(forAllMovieSlot()));  //для арифметической операции
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(forAllMovieSlot()));    //для арифметической операции
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(forResultSlot()));   //для получения результата


    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(forTextEditResultSlot()));     //для получения промежуточного результата
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(forTextEditResultSlot()));   //для получения промежуточного результата
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(forTextEditResultSlot()));   //для получения промежуточного результата
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(forTextEditResultSlot()));   //для получения промежуточного результата
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(forTextEditResultSlot()));   //для получения промежуточного результата
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(forTextEditResultSlot()));   //для получения промежуточного результата

    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(forTextReset()));   //для сброса



   //сделать поле ввода  активным при запуске программы
ui->lineEdit->setFocus();

   //разрешен только ввод чисел типа double или int
      QDoubleValidator *my_Validator = new QDoubleValidator();//создание нового объекта QDoubleValidator
      ui->lineEdit->setValidator(my_Validator);//подключение регулярного выражения к текстовому полю lineEdit

     //можно указать название, а можно номер из enum Qt::Key, но не все клавиши срабатывают, потому что надо смотреть это Unicode или ANSII

      ui->pushButton->setShortcut(Qt::Key_Plus);//при нажатии клавиши клавиатуры Return будет срабатывать кнопка + с objectName pushButton
      ui->pushButton_2->setShortcut(Qt::Key_Minus);//при нажатии клавиши клавиатуры Return будет срабатывать кнопка - с objectName pushButton_2
      ui->pushButton_3->setShortcut(Qt::Key_Asterisk);//при нажатии клавиши клавиатуры Return будет срабатывать кнопка * с objectName pushButton_3
      ui->pushButton_4->setShortcut(Qt::Key_Slash);//при нажатии клавиши клавиатуры Return будет срабатывать кнопка / с objectName pushButton_4
      ui->pushButton_5->setShortcut(Qt::Key_Return);//при нажатии клавиши клавиатуры Return будет срабатывать кнопка Enter с objectName pushButton_5

}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
 Алгоритм работы:
1)получаем фокус
2)вводим первое число,
проверяем есть ли знак в памяти
3)нажимаем на один из знаков + - * / это число и знак сохраняются,
3.1)нажимаем + первое число=первое число+другое число
3.1.1)получаем фокус
3.2)нажимаем + первое число=первое число+другое число
3.2.1)получаем фокус
3.3)нажимаем + первое число=первое число+другое число
3.3.1)получаем фокус
3.4)нажимаем + первое число=первое число+другое число
3.4.1)получаем фокус
3.5)нажимаем = получаем первое число





Требования:
1)при этом должны вводиться только цифры и точка
2)поле ввода становится активным перед вводом каждого числа
3!нельзя делить на ноль

4!возможность ввода знаков с клавиатуры
5!добавить другие функции


objectName:
lineEdit     - это поле для ввода чисел
pushButton   - это знак +
pushButton_2 - это знак -
pushButton_3 - это знак *
pushButton_4 - это знак /
pushButton_5 - это знак =

Переменные:
первое значение - insertvalue
второе значение - resultvalue
арифметические знаки - oldsign,sign
*/


static double insertvalue;//значение, введенное в editText, пишется static, так как получает значение внутри другой функции
static double resultvalue;//введенное значение для хранения результата, пишется static, так как получает значение внутри другой функции
static QString sign;//знак арифметического действия, пишется static, так как получает значение внутри другой функции
static QString oldsign;//предыдущий знак арифметического действия, пишется static, так как получает значение внутри другой функции

void MainWindow::forValueSlot()//поместить значение в поле
{

}


void MainWindow::forResultSlot(){

   ui->lineEdit->setText(QString::number(resultvalue));//показ результата в текстовом поле
}

void MainWindow::forAllMovieSlot()
{
    insertvalue=ui->lineEdit->text().toDouble();//поместить значение в firstvalue и сделать ее тип double

   QPushButton *buttonSender = qobject_cast<QPushButton *>(sender()); // помещение в указатель buttonSender объекта отправителя
        QString buttonText = buttonSender->text();// помещение в buttonText текст отправителя, на который был создан указатель
        oldsign=sign;
        sign=buttonText;//получение знака действия
    //
    if(sign=='+') {
        resultvalue=resultvalue+insertvalue;
    }
    else if (sign=='-') {
        resultvalue=resultvalue-insertvalue;
    }
    else if (sign=='*') {
        if(resultvalue==0){resultvalue=1;}
        resultvalue=resultvalue*insertvalue;
    }
    else if(sign=='/'){
        if((insertvalue>0)|(insertvalue<0)){
            resultvalue=resultvalue/insertvalue;
        }
        else if(sign=="Сброс"){
           resultvalue=insertvalue=0;
            }
        else resultvalue=0;
    }
    else {;
    }
    //
    //insertvalue=0;
    //ui->lineEdit->setText(QString::number(resultvalue));//показ результата в текстовом поле
    ui->lineEdit->setText("");
    ui->lineEdit->setFocus();
}



void MainWindow::forTextReset()//сброс
{
      resultvalue=insertvalue=0;
      sign=oldsign="";
       ui->lineEdit->setText(QString::number(resultvalue));//показ результата в текстовом поле
      }

void MainWindow::forTextEditResultSlot()//для получения промежуточного результата в текстовом поле
{
      ui->textEdit->setText("insertvalue ввел = "+QString::number(insertvalue)+"\n"+"sign = "+sign+"\n"+"oldsign = "+oldsign+"\n"+"resultvalue результат = "+QString::number(resultvalue)+"\n");//показ промежуточного результата в текстовом поле
}


/*
QObject *obj = new QTimer;          // QTimer inherits QObject

QTimer *timer = qobject_cast<QTimer *>(obj);
// timer == (QObject *)obj

QAbstractButton *button = qobject_cast<QAbstractButton *>(obj);
// button == 0
*/
