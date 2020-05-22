#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "./Proj/com.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_styleWhite_triggered();
    void on_styleBlack_triggered();
    void on_yesRadioButton_clicked();
    void on_noRadioButton_clicked();
    void on_closeAction_triggered();

    void on_openAction_triggered();

    void on_fontAction_triggered();

    void on_colorAction_triggered();

    void on_aboutAction_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
