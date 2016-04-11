#ifndef ERRORCALCULATIONDIALOG_H
#define ERRORCALCULATIONDIALOG_H

#include <QDialog>
#include "objectvariable.h"

namespace Ui {
class ErrorCalculationDialog;
}

class ErrorCalculationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ErrorCalculationDialog(QWidget *parent = 0);
    ~ErrorCalculationDialog();

private:
    Ui::ErrorCalculationDialog *ui;
};

#endif // ERRORCALCULATIONDIALOG_H
