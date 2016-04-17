#ifndef DATAWINDOW_H
#define DATAWINDOW_H

#include <QWidget>
#include "datalogger.h"
namespace Ui {
class DataWindow;
}

class DataWindow : public QWidget
{
	Q_OBJECT

public:
	explicit DataWindow(QWidget *parent = 0);
	~DataWindow();
	QString filename;
private:
	Ui::DataWindow *ui;
	DataLogger myDataLogger;

public slots:
	void dataEntryFinished();
	void addData(QList<Player> newData);

private slots:
	void on_pushButton_display_data_released();
	void on_pushButton_load_released();
	void on_pushButton_save_released();
public slots:

};

#endif // DATAWINDOW_H
