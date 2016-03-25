#ifndef MASKINGWINDOW_H
#define MASKINGWINDOW_H

#include <QDialog>

namespace Ui {
class MaskingWindow;
}

class MaskingWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MaskingWindow(QWidget *parent = 0);
    ~MaskingWindow();

private:
    Ui::MaskingWindow *ui;
};

#endif // MASKINGWINDOW_H
