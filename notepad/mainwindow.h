#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QMessageBox>
#include <QFile>
#include <QDir>
#include <QFileDialog>
#include <QTextStream>
#include <QFont>
#include <QFontDialog>
#include <QColor>
#include <QColorDialog>
#include <QDateTime>
#include <QUrl>
#include <QDesktopServices>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionopen_O_triggered();

    void on_actionsave_S_triggered();

    void on_actionsave_other_triggered();
    void set_Font_Slot();
    void set_Color_Slot();
    void set_DataTime_Slot();
    void set_Help_Slot();
    void set_About_Slot();

private:
    Ui::MainWindow *ui;
    QString savefilename;
};

#endif // MAINWINDOW_H
