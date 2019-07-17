#include "mainwindow.h"
#include "ui_mainwindow.h"
//Ui::MainWindow是在ui_mainwindow.h文件中进行的定义
//这里面就是窗体以及里面的各种控件
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);//注意this和ui变量之间的区别
    //ui应该指的是界面中的空间，是mainwindow.h中定义的变量
    //这个ui并不是指向MainWidow变量，而是指向Ui::MainWindow这个变量
    //this只是指向MainWindow的一个指针变量。MainWindow和Ui::MainWindow虽然名字是一样的，但是是不同的变量
    QObject::connect(ui->calButton,SIGNAL(clicked),this,SLOT(on_calButton_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_calButton_clicked()
{
#if 1
    int output = 0;
    int firstval = ui->firstVar->text().toInt();
    int secondval = ui->secondVar->text().toInt();
    int num_i = ui->CalcomboBox->currentIndex();
    switch (num_i) {
    case 0:
        output = firstval + secondval;
        break;
    case 1:
        output = firstval - secondval;
        break;
    case 2:
        output = firstval*secondval;
        break;
    case 3:
        if(!secondval){
            QMessageBox::warning(this,"Output Error!","Second value can't be zero!");
            return;
        }
        output = firstval/secondval;
    //default:

    }
    ui->output->setText(QString::number(output));

    QMessageBox::information(this,"Output",QString::number(output));

#endif
}
