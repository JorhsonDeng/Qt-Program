#ifndef ABOUT_H
#define ABOUT_H

#include <QDialog>
#include <QMovie>

namespace Ui {
class about;
}

class about : public QDialog
{
    Q_OBJECT

public:
    explicit about(QWidget *parent = nullptr);
    ~about();

private:
    Ui::about *ui;
    QMovie *movie;

private slots:
    void start_putton();//开始动画
    void stop_putton();//停止动画
    void on_startButton_clicked();
    void on_stopButton_clicked();
};

#endif // ABOUT_H
