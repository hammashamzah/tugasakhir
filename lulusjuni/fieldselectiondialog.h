#ifndef FIELDSELECTIONDIALOG_H
#define FIELDSELECTIONDIALOG_H

#include <QDialog>

namespace Ui {
class FieldSelectionDialog;
}

class FieldSelectionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FieldSelectionDialog(QWidget *parent = 0);
    ~FieldSelectionDialog();

private:
    Ui::FieldSelectionDialog *ui;
};

#endif // FIELDSELECTIONDIALOG_H
