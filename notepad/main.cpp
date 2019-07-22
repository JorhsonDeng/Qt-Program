#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QPixmap>
#include <QSplashScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPixmap pixmap("screen.PNG");//加载一张图片到pixmap对象中,类型是PNG类型的
    QSplashScreen splash(pixmap);//将该pixmap加载到splash对象中
    splash.show();//显示图片
    for (int i = 0;i<1000000000;i++) {
        //在这里进行程序的加载工作
    }
    MainWindow w;   //创建主窗口
    w.show();       //显示主窗口
    splash.finish(&w);  //显示主窗口之后，把图片关闭
    return a.exec();
}
