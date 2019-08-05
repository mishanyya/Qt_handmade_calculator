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


    ui->pushButton_7->setShortcut(Qt::Key_1);
    ui->pushButton_8->setShortcut(Qt::Key_2);
    ui->pushButton_9->setShortcut(Qt::Key_3);
    ui->pushButton_10->setShortcut(Qt::Key_4);
    ui->pushButton_11->setShortcut(Qt::Key_5);
    ui->pushButton_12->setShortcut(Qt::Key_6);
    ui->pushButton_13->setShortcut(Qt::Key_7);
    ui->pushButton_14->setShortcut(Qt::Key_8);
    ui->pushButton_15->setShortcut(Qt::Key_9);
    ui->pushButton_16->setShortcut(Qt::Key_0);
    ui->pushButton_16->setShortcut(42);//запятая

}

MainWindow::~MainWindow()
{
    delete ui;
}

/*

Требования:
1)при этом должны вводиться только цифры и точка
2)поле ввода становится активным перед вводом каждого числа
3!нельзя делить на ноль

4!возможность ввода знаков с клавиатуры
5!добавить другие функции


*/

static double previousvalue;//сохраненное предыдущее значение, не выводится в editText, пишется static
static double insertvalue;//значение, введенное в editText, пишется static, так как работает внутри другой функции
static double resultvalue;//введенное значение для хранения результата, пишется static, так как работает внутри другой функции

static QString oldsign;//предыдущий знак арифметического действия, пишется static, так как работает внутри другой функции
static QString sign;//знак арифметического действия, пишется static, так как получает значение внутри другой функции

static int countclick=0;//количество раз, нажатых на кнопки арифметических действий, пишется static, так как работает внутри другой функции

void MainWindow::forValueSlot()//поместить значение в поле
{
    oldsign=sign;//присвоение нового значения знака операции старому

}

void MainWindow::forAllMovieSlot()
{
   QPushButton *buttonSender = qobject_cast<QPushButton *>(sender()); // помещение в указатель buttonSender объекта отправителя
        QString buttonText = buttonSender->text();// помещение в buttonText текст отправителя, на который был создан указатель

        if(countclick==0){//самое первое введенное значение
       //replace(',', '.') нужно для замены запятой на точку, так как с запятой тип double не работает
        previousvalue=ui->lineEdit->text().replace(',', '.').toDouble();//поместить значение в previousvalue и сделать ее тип double

            //previousvalue=ui->lineEdit->text().toDouble();//поместить значение в previousvalue и сделать ее тип double
        }
        else{//остальные введенные значения
            insertvalue=ui->lineEdit->text().replace(',', '.').toDouble();//поместить значение в insertvalue и сделать ее тип double
        }

        sign=buttonText;//получение знака действия

    /*отсюда начинаются арифметические операции*/
    if(oldsign=='+') {
        if(countclick==1){//самое первое введенное значение
            resultvalue=previousvalue+insertvalue;//самое первое действие
        }
        else{//остальные введенные значения
            resultvalue=resultvalue+insertvalue;//остальные действия
        }
    }

    else if (oldsign=='-') {
        if(countclick==1){//самое первое введенное значение
            resultvalue=previousvalue-insertvalue;//самое первое действие
        }
        else{//остальные введенные значения
            resultvalue=resultvalue-insertvalue;//остальные действия
        }
    }

    else if (oldsign=='*') {
        if(countclick==1){//самое первое введенное значение
            resultvalue=previousvalue*insertvalue;//самое первое действие
        }
        else{//остальные введенные значения
            resultvalue=resultvalue*insertvalue;//остальные действия
        }
    }

    else if(oldsign=='/'){
        if(countclick==1){//самое первое введенное значение
            resultvalue=previousvalue/insertvalue;//самое первое действие
        }
        else{//остальные введенные значения
            resultvalue=resultvalue/insertvalue;//остальные действия
        }
    }

    else {;
    }
    /*здесь заканчиваются арифметические операции*/

    countclick++;
    ui->lineEdit->setText("");
    ui->lineEdit->setFocus();
}

void MainWindow::forResultSlot(){//показать результат в текстовом поле

    if(countclick==0){//самое первое введенное значение
        previousvalue=ui->lineEdit->text().toDouble();//поместить значение в previousvalue и сделать ее тип double
    }
    else{//остальные введенные значения
        insertvalue=ui->lineEdit->text().toDouble();//поместить значение в previousvalue и сделать ее тип double
    }

    if(sign=='+') {
        if(countclick==1){//самое первое введенное значение
            resultvalue=previousvalue+insertvalue;//самое первое действие
        }
        else{//остальные введенные значения
            resultvalue=resultvalue+insertvalue;//остальные действия
        }
    }

    else if (sign=='-') {
        if(countclick==1){//самое первое введенное значение
            resultvalue=previousvalue-insertvalue;//самое первое действие
        }
        else{//остальные введенные значения
            resultvalue=resultvalue-insertvalue;//остальные действия
        }
    }

    else if (sign=='*') {
        if(countclick==1){//самое первое введенное значение
            resultvalue=previousvalue*insertvalue;//самое первое действие
        }
        else{//остальные введенные значения
            resultvalue=resultvalue*insertvalue;//остальные действия
        }
    }

    else if(sign=='/'){
        if(countclick==1){//самое первое введенное значение
            resultvalue=previousvalue/insertvalue;//самое первое действие
        }
        else{//остальные введенные значения
            resultvalue=resultvalue/insertvalue;//остальные действия
        }
    }

    else {;
    }

   ui->lineEdit->setText(QString::number(resultvalue));
    previousvalue=countclick=0;
    insertvalue=resultvalue;
    resultvalue=0;
   sign=oldsign="";

   ui->lineEdit->setFocus();
}

void MainWindow::forTextReset()//сброс
{
      resultvalue=insertvalue=previousvalue=countclick=0;
      sign=oldsign="";

      ui->lineEdit->setText(QString::number(resultvalue));//показ результата в текстовом поле
      }

void MainWindow::forTextEditResultSlot()//для получения промежуточного результата в текстовом поле
{
      ui->textEdit->setText("previousvalue промежуточное число = "+QString::number(previousvalue)+"\n"+
                            "insertvalue ввел = "+QString::number(insertvalue)+"\n"+
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

