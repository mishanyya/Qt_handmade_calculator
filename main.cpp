#include "mainwindow.h"
#include <QApplication>  //подключает класс для работы с QApplication, добавляется обязательно !!!



int main(int argc, char *argv[])
{
    QApplication a(argc, argv); //создает экземпляр класса QApplication, обычно он один, должно быть обязательно в коде main()!!!
    MainWindow w;  //создает окно 'w', оно обычно только одно, должно быть обязательно в коде main()!!!

    w.show();//показывает окно приложения 'w' , должно быть обязательно в коде main()!!!
    return a.exec();//запускает приложение, должно быть обязательно в коде main()!!!
}


