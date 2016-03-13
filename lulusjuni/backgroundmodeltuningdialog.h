#ifndef BACKGROUNDMODELTUNINGDIALOG_H
#define BACKGROUNDMODELTUNINGDIALOG_H

#include <QDialog>

namespace Ui {
class BackgroundModelTuningDialog;
}

class BackgroundModelTuningDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BackgroundModelTuningDialog(QWidget *parent = 0);
    ~BackgroundModelTuningDialog();

private:
    Ui::BackgroundModelTuningDialog *ui;
};

#endif // BACKGROUNDMODELTUNINGDIALOG_H
