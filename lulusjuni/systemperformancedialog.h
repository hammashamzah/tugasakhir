#ifndef SYSTEMPERFORMANCEDIALOG_H
#define SYSTEMPERFORMANCEDIALOG_H

#include <QDialog>

namespace Ui {
class SystemPerformanceDialog;
}

class SystemPerformanceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SystemPerformanceDialog(QWidget *parent = 0);
    ~SystemPerformanceDialog();

private:
    Ui::SystemPerformanceDialog *ui;
};

#endif // SYSTEMPERFORMANCEDIALOG_H
