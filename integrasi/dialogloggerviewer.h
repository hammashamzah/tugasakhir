#ifndef DIALOGLOGGERVIEWER_H
#define DIALOGLOGGERVIEWER_H

#include <QDialog>

namespace Ui {
class DialogLoggerViewer;
}

class DialogLoggerViewer : public QDialog
{
    Q_OBJECT

public:
    explicit DialogLoggerViewer(QWidget *parent = 0);
    ~DialogLoggerViewer();

private:
    Ui::DialogLoggerViewer *ui;
};

#endif // DIALOGLOGGERVIEWER_H
