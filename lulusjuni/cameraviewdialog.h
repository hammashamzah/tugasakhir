#ifndef CAMERAVIEWDIALOG_H
#define CAMERAVIEWDIALOG_H

#include <QDialog>

namespace Ui {
class CameraViewDialog;
}

class CameraViewDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CameraViewDialog(QWidget *parent = 0);
    ~CameraViewDialog();

private:
    Ui::CameraViewDialog *ui;
};

#endif // CAMERAVIEWDIALOG_H
