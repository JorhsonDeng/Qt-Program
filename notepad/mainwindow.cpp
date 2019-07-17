#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("new.txt    notepad");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionopen_O_triggered()
{
    if(ui->textEdit->document()->isModified()){
        qDebug()<<"the text is modified!";
        QMessageBox::information(this," ","Save this text or not");
    }else {
        qDebug()<<"the text is not modified!";
        this->setWindowTitle("untitle.txt  notepad");
    }
}
