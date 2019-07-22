#include "about.h"
#include "ui_about.h"

about::about(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::about)
{
    ui->setupUi(this);
    //*.gif文件必须在build-notepad-Desktop_Qt_5_12_3_MinGW_64_bit-Debug文件目录下
    this->movie = new QMovie("cat&mouse.gif");
    ui->label_Movie->setMovie(this->movie);
    this->movie->start();
    QObject::connect(ui->startButton,SIGNAL(clicked()),this,SLOT(start_putton()));
    QObject::connect(ui->stopButton,SIGNAL(clicked()),this,SLOT(stop_putton()));
}

about::~about()
{
    delete ui;
}
void about::start_putton()
{
    this->movie->start();
}
void about::stop_putton()
{
    this->movie->stop();
}

void about::on_startButton_clicked()
{
    //this->movie->start();
}

void about::on_stopButton_clicked()
{
    //this->movie->stop();
}
