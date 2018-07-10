#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <cmath>
#include <QMessageBox>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionCo_to_jest_triggered();

    void on_oblicz_clicked();

    void on_actionOblicz_triggered();


    void on_opis_clicked();

    void on_actionSprawd_E_triggered();

    void on_ok_clicked();

    void on_actionCo_to_jest_2_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
