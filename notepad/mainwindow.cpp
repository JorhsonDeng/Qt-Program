#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "about.h"
//#include "ui_about.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(savefilename+"notepad");
    QObject::connect(ui->actionColor,SIGNAL(triggered()),this,SLOT(set_Color_Slot()));
    QObject::connect(ui->actionFont,SIGNAL(triggered()),this,SLOT(set_Font_Slot()));
    QObject::connect(ui->actionTime,SIGNAL(triggered()),this,SLOT(set_DataTime_Slot()));\
    //这里将Action函数和textEdit对象本身具有的一些函数相关联
    //在构造connection函数的时候，将receiver定为ui->textEdit对象
    QObject::connect(ui->actioncopy_C,SIGNAL(triggered()),ui->textEdit,SLOT(copy()));
    QObject::connect(ui->actioncut_X,SIGNAL(triggered()),ui->textEdit,SLOT(cut()));
    QObject::connect(ui->actionpaste_P,SIGNAL(triggered()),ui->textEdit,SLOT(paste()));
    QObject::connect(ui->actionAll_A,SIGNAL(triggered()),ui->textEdit,SLOT(selectAll()));

    //将help action和相应的函数进行连接
    QObject::connect(ui->actionhelp,SIGNAL(triggered()),this,SLOT(set_Help_Slot()));
    //在这里显示dialog对话框
    QObject::connect(ui->actionAbout,SIGNAL(triggered()),this,SLOT(set_About_Slot()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionopen_O_triggered()
{
#if 0
    if(ui->textEdit->document()->isModified()){
        qDebug()<<"the text is modified!";
        QMessageBox::information(this," ","Save this text or not");
    }else {
        qDebug()<<"the text is not modified!";
        this->setWindowTitle("untitle.txt  notepad");
    }
#endif
    QString curpath = QDir::currentPath();
    QString filter = "program files(*.h,*.c);;text files(*.txt);;all files(*.*)";
    QString filename = QFileDialog::getOpenFileName(this,"open a file",curpath,filter);
    qDebug() << "files name is : "<<filename;
    if(filename.isEmpty())
    {
        QMessageBox::information(this,"Error Message","file cannot null");
        return;
    }
    savefilename = filename;
    QFile file(filename);
    if(!file.exists()){//文本不存在
        return;
    }
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        return;
    }
    //利用QtextStream类来读写文件
    QTextStream FileStream(&file);
    ui->textEdit->setText(FileStream.readAll());
    file.close();
    this->setWindowTitle(savefilename);
    return;
}

void MainWindow::on_actionsave_other_triggered()
{
    //另保存文件
    qDebug()<<"execute save command3!";
    QString curfile = QDir::currentPath();
    QString filter = "program files(*.h,*.c);;text files(*.txt);;all files(*.*)";
    QString filename = QFileDialog::getSaveFileName(this,"save files",curfile,filter);
    if(filename.isEmpty())
    {
        QMessageBox::information(this,"Error Message","file name cannot be NULL!");
        return;
    }
    QFile file(filename);
    //QFile file.setFileName(filename);这个定义和上一句的定义是一样的
    if(!file.open(QIODevice::WriteOnly|QIODevice::Text))
    {
        return;
    }
    QTextStream filestream(&file);//这里传进的是指针变量
    QString str = ui->textEdit->toPlainText();//这里注意是Qstring,而不是QTextString
    filestream << str;
    //filestream << ui->textEdit->toPlainText();
    file.close();//这里不进行关闭也没什么关系，file是局部变量
    this->setWindowTitle(filename+"----notepad");
    return;
}

void MainWindow::on_actionsave_S_triggered()
{
    qDebug()<<"execute save command1!";
    if(savefilename.isEmpty())
    {
        qDebug()<<"execute save command2!";
        on_actionsave_other_triggered();
        qDebug()<<"execute save command4!";
        return;
    }
    QFile file(savefilename);
    //QFile file.setFileName(savefilename);这个定义和上一句的定义是一样的
    if(!file.open(QIODevice::WriteOnly|QIODevice::Text))
    {
        return;
    }
    QTextStream filestream(&file);//这里传进的是指针变量
    QString str = ui->textEdit->toPlainText();//这里注意是Qstring,而不是QTextString
    filestream << str;
    //filestream << ui->textEdit->toPlainText();
    file.close();//这里不进行关闭也没什么关系，file是局部变量
    this->setWindowTitle(savefilename+"----notepad");
    return;
}

void MainWindow::set_Font_Slot()
{
    bool ok;
    QFont font= QFontDialog::getFont(&ok,this);//从字体的对话框中得到所想设置的字体和大小
    if(ok)
        ui->textEdit->setFont(font);//如果得到的值是有效的，则直接将得到的字体变量设置到文本中
    else {
        QMessageBox::information(this,"Error Message!","Set font error!");
        return;
    }

}

void MainWindow::set_Color_Slot()
{
    QColor color = QColorDialog::getColor(Qt::red,this);//从color dialog中得到颜色的值，并设置默认颜色为红色
    if(color.isValid())//这里判断颜色是否有效
        ui->textEdit->setTextColor(color);//如果得到的颜色有效果，则将文本的字体设置为得到的颜色
    else {
        QMessageBox::information(this,"Error Message！","Set Color Error!");
        return;
    }
}


void MainWindow::set_DataTime_Slot()
{
    QDateTime cur = QDateTime::currentDateTime();
    qDebug()<<"the time is:"<<cur;
    QString time = cur.toString("yyyy-mm-dd hh:mm:ss.ms");
    ui->textEdit->append(time);
    return;
}
void MainWindow::set_Help_Slot()
{
    //打开默认网址所用的浏览器是电脑桌面默认的浏览器
    QDesktopServices::openUrl(QUrl("https://www.baidu.com"));
}
void MainWindow::set_About_Slot()
{
    //about dialog;
    //这里必须用动态分配内存的方式，如果直接用局部变量的话，是不行的
    //因为这个函数执行完毕之后，在这个函数中申请的堆栈就会释放掉，相应的对话框也显示不出来
    about *dialog = new about;
    dialog->show();
}
