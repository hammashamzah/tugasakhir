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
    void setFrame_1(QImage img);
    void setFrame_2(QImage img);
    void setFrame_3(QImage img);

public:
    explicit FieldSelectionDialog(QWidget *parent = 0);
    ~FieldSelectionDialog();

private slots:
    void on_cameraSelectCombo_currentIndexChanged(int index);

private:
    Ui::FieldSelectionDialog *ui;
    QImage frameCamera_1;
    QImage frameCamera_2;
    QImage frameCamera_3;
};

#endif // FIELDSELECTIONDIALOG_H
