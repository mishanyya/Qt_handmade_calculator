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
#include <QLocale>           //подключает класс для работы с локальной раскладкой клавиатуры, добавляется при необходимости!

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(forAllMovieSlot()));         //для арифметической операции
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(forAllMovieSlot()));  //для арифметической операции
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(forAllMovieSlot()));  //для арифметической операции
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(forAllMovieSlot()));    //для арифметической операции
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(forAllMovieSlot()));    //для получения результата

    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(forTextReset()));   //для сброса
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(forTextEditResultSlot()));   //для получения промежуточного результата

    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(forSymbolEnter()));   //для ввода цифр в текстовое поле
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(forSymbolEnter()));   //для ввода цифр в текстовое поле
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(forSymbolEnter()));   //для ввода цифр в текстовое поле
    connect(ui->pushButton_10, SIGNAL(clicked()), this, SLOT(forSymbolEnter()));   //для ввода цифр в текстовое поле
    connect(ui->pushButton_11, SIGNAL(clicked()), this, SLOT(forSymbolEnter()));   //для ввода цифр в текстовое поле
    connect(ui->pushButton_12, SIGNAL(clicked()), this, SLOT(forSymbolEnter()));   //для ввода цифр в текстовое поле
    connect(ui->pushButton_13, SIGNAL(clicked()), this, SLOT(forSymbolEnter()));   //для ввода цифр в текстовое поле
    connect(ui->pushButton_14, SIGNAL(clicked()), this, SLOT(forSymbolEnter()));   //для ввода цифр в текстовое поле
    connect(ui->pushButton_15, SIGNAL(clicked()), this, SLOT(forSymbolEnter()));   //для ввода цифр в текстовое поле
    connect(ui->pushButton_16, SIGNAL(clicked()), this, SLOT(forSymbolEnter()));   //для ввода цифр в текстовое поле
    connect(ui->pushButton_17, SIGNAL(clicked()), this, SLOT(forSymbolEnter()));   //для ввода запятой в текстовое поле

    connect(ui->pushButton_18, SIGNAL(clicked()), this, SLOT(forTextClean()));//для сброса содержимого lineEdit


    //сделать поле ввода  активным при запуске программы
    //ui->lineEdit->setFocus();

    //сделать поле ввода недоступным для ввода
    ui->lineEdit->setReadOnly(1);

    //разрешен только ввод чисел типа double или int
    QDoubleValidator *my_Validator = new QDoubleValidator();//создание нового объекта QDoubleValidator
    ui->lineEdit->setValidator(my_Validator);//подключение регулярного выражения к текстовому полю lineEdit

    //можно указать название или номер из enum Qt::Key для ANSII, но не все клавиши срабатывают, потому что различаются Unicode или ANSII
    ui->pushButton->setShortcut(Qt::Key_Plus);//value +
    ui->pushButton_2->setShortcut(Qt::Key_Minus);//value -
    ui->pushButton_3->setShortcut(42);//value *
    ui->pushButton_4->setShortcut(Qt::Key_Slash);//value /
    ui->pushButton_5->setShortcut(Qt::Key_Enter);//value Enter
    ui->pushButton_5->setShortcut(Qt::Key_Return);//value Enter

    ui->pushButton_7->setShortcut(Qt::Key_1);//value 1
    ui->pushButton_8->setShortcut(Qt::Key_2);//value 2
    ui->pushButton_9->setShortcut(Qt::Key_3);//value 3
    ui->pushButton_10->setShortcut(Qt::Key_4);//value 4
    ui->pushButton_11->setShortcut(Qt::Key_5);//value 5
    ui->pushButton_12->setShortcut(Qt::Key_6);//value 6
    ui->pushButton_13->setShortcut(Qt::Key_7);//value 7
    ui->pushButton_14->setShortcut(Qt::Key_8);//value 8
    ui->pushButton_15->setShortcut(Qt::Key_9);//value 9
    ui->pushButton_16->setShortcut(48);//value 0
    ui->pushButton_17->setShortcut(44);//value , 44 или 46 работают в зависимости от языка клавиатуры Rus
   // ui->pushButton_17->setShortcut(46);//value . 44 или 46 работают в зависимости от языка клавиатуры Eng

}

MainWindow::~MainWindow()
{
    delete ui;
}

/*

Требования:
1)при этом должны вводиться только цифры и точка
2)нельзя делить на ноль
3)возможность ввода знаков с клавиатуры
4!возможность стирать введенное значение с клавиатуры

5!фильтр ввода одного нуля и одной запятой

*/

static double insertvalue;//значение, введенное в editText, пишется static, так как работает внутри другой функции
static double resultvalue;//введенное значение для хранения результата, пишется static, так как работает внутри другой функции

static QString oldsign;//предыдущий знак арифметического действия, пишется static, так как работает внутри другой функции
static QString sign;//знак арифметического действия, пишется static, так как получает значение внутри другой функции

static int countclick=0;//количество раз, нажатых на кнопки арифметических действий, пишется static, так как работает внутри другой функции

void MainWindow::forAllMovieSlot()
{
   QPushButton *buttonSender = qobject_cast<QPushButton *>(sender()); // помещение в указатель buttonSender объекта отправителя
        QString buttonText = buttonSender->text();// помещение в buttonText текст отправителя, на который был создан указатель
        sign=buttonText;//получение знака действия

        if(countclick<1){//если введено только одно первое значение и нажат знак sign
        resultvalue=ui->lineEdit->text().replace(',', '.').toDouble();//поместить значение в previousvalue и сделать ее тип double
         }
        else{//если введено несколько значений и нажат знак sign
            insertvalue=ui->lineEdit->text().replace(',', '.').toDouble();//поместить значение в insertvalue и сделать ее тип double

            /*отсюда начинаются операции*/
            if(oldsign=='+') {
                      resultvalue=resultvalue+insertvalue;
            }
            else if (oldsign=='-') {
                    resultvalue=resultvalue-insertvalue;
            }
            else if (oldsign=='*') {
                    resultvalue=resultvalue*insertvalue;
            }
            else if(oldsign=='/'){
                if((insertvalue<0)|(insertvalue>0)){
                   resultvalue=resultvalue/insertvalue;
                }
            }
            else {
                ui->lineEdit->setText("Действие не выбрано!!!");
            }
            /*здесь заканчиваются арифметические операции*/
        }

        countclick++;
        ui->lineEdit->setText("");
        oldsign=sign;//присвоение нового значения знака операции старому

if(sign=='='){
    ui->lineEdit->setText(QString::number(resultvalue));//показ результата в текстовом поле
}

MainWindow::forTextEditResultSlot();
}

void MainWindow::forTextClean(){//очистка поля ввода lineEdit
    ui->lineEdit->setText("");
}




void MainWindow::forTextReset(){//сброс
    ui->lineEdit->setText("");

    resultvalue=insertvalue=countclick=0;
      sign=oldsign="";

      MainWindow::forTextEditResultSlot();
}

void MainWindow::forTextEditResultSlot()//для получения промежуточного результата в текстовом поле
{
      ui->textEdit->setText("insertvalue ввел = "+QString::number(insertvalue)+"\n"+
                            "resultvalue результат = "+QString::number(resultvalue)+"\n"+
                            "----------------------------------------"+"\n"+
                            "oldsign предыдущий знак = "+oldsign+"\n"+
                            "sign знак= "+sign+"\n"+
                            "----------------------------------------"+"\n"+
                            "countclick количество нажатий знаков = "+QString::number(countclick));
}

void MainWindow::forSymbolEnter()//для ввода цифр в текстовое поле
{
    QPushButton *buttonSender = qobject_cast<QPushButton *>(sender()); // помещение в указатель buttonSender объекта отправителя
         QString buttonText = buttonSender->text();// помещение в buttonText текст отправителя, на который был создан указатель
         ui->lineEdit->insert(buttonText);//добавляет символы в текстовое поле
}


