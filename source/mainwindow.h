#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QLabel>
#include<QStatusBar>
#include<QMouseEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    //QPixmap modifiedPixmap_;
public:
        // QPixmap modifiedPixmap_;
    //QString fileName;
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
               //void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    QLabel *statusLabel;
    QLabel *MousePosLabel;
protected:
    void mousePressEvent(QMouseEvent *e);
};

#endif // MAINWINDOW_H
