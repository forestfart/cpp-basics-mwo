#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow //dziedziczenie z QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0); //konstruktor
    ~MainWindow(); //destruktor

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
