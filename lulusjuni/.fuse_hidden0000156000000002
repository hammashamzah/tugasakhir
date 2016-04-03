#ifndef FIELDSELECTIONDIALOG_H
#define FIELDSELECTIONDIALOG_H

#include <QDialog>

namespace Ui {
class FieldSelectionDialog;
}

class FieldSelectionDialog : public QDialog
{
    Q_OBJECT

public slots:
    void setFirstFrame_1(QImage img);
    void setFirstFrame_2(QImage img);
    void setFirstFrame_3(QImage img);

public:
    explicit FieldSelectionDialog(QWidget *parent = 0);
    ~FieldSelectionDialog();

private slots:
    void on_cameraSelectCombo_currentIndexChanged(int index);

private:
    Ui::FieldSelectionDialog *ui;
    QImage firstFrameCamera_1;
    QImage firstFrameCamera_2;
    QImage firstFrameCamera_3;
};

#endif // FIELDSELECTIONDIALOG_H
