#ifndef TRACKINGVIEWDIALOG_H
#define TRACKINGVIEWDIALOG_H

#include <QDialog>

namespace Ui {
class TrackingViewDialog;
}

class TrackingViewDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TrackingViewDialog(QWidget *parent = 0);
    ~TrackingViewDialog();

private:
    Ui::TrackingViewDialog *ui;
};

#endif // TRACKINGVIEWDIALOG_H
