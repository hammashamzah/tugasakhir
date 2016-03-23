#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

public slots:
    void showMousePosition(QPoint& pos);
    void showClickPosition(QPoint& pos);

private slots:
    void on_pushButton_generateTransMat_clicked();
};

#endif // MAINWINDOW_H
