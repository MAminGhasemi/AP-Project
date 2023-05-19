#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "farm_page.h"

namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void update_bar();
    void on_play_butt_clicked();
    void on_enter_butt_clicked();
    void on_create_butt_clicked();
    void on_pushButton_clicked();


private:
    QTimer *timer;
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
