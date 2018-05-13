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

private slots:
    void on_actionCopy_triggered();

    void on_actionCut_triggered();

    void on_actionPaste_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionNew_triggered();

    void on_actionSave_As_triggered();

private:
    Ui::MainWindow *ui;
    void saveToFile(QString filePath);
};

#endif // MAINWINDOW_H
