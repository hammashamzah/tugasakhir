#ifndef DATAWINDOW_H
#define DATAWINDOW_H
#define TOTAL_FRAME 40
#include <QWidget>
#include "datalogger.h"
#include "freezetablewidget.h"
#include <QGraphicsScene>
#include "playervisual.h"
#include <QTimer>
#include <QStandardItemModel>
#include <QStringList>
#include <QDebug>
#include "player.h"
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
	void PlayBack();
	void updateModel(QVector<QList<Player> > resultData);
	QStandardItemModel *model;
	QVector<QList<Player> > setRandomQList();
private:
	Ui::DataWindow *ui;
	DataLogger myDataLogger;
	QList<Player> tempSinglePlayerRec;
	QVector<QList<Player> > playerData;
	QVector<QList<Player> > tempPlayersData;
	int idSelected;
	QList<int> frameSelected;
	void getItemSelected();
	int frameNumber;
	QTimer *timer;
public slots:
	void dataEntryFinished();
	void addData(QList<Player> newData);
private slots:
	void on_pushButton_display_data_released();
	void on_pushButton_load_released();
	void on_pushButton_save_released();
	void on_pushButton_cut_clicked();
	void on_pushButton_paste_clicked();
	void on_pushButton_refresh_clicked();
	void updatePosition();
	void on_pushButton_playbackStart_clicked();
	void on_slider_playback_valueChanged(int value);
	void on_pushButton_reconstruct_clicked();
};
#endif // DATAWINDOW_H