#ifndef DATAWINDOW_H
#define DATAWINDOW_H

#include <QWidget>

namespace Ui {
class DataWindow;
}

class DataWindow : public QWidget
{
    Q_OBJECT

public:
    explicit DataWindow(QWidget *parent = 0);
    ~DataWindow();

private:
    Ui::DataWindow *ui;
};

#endif // DATAWINDOW_H
