#ifndef DATAWINDOW_H
#define DATAWINDOW_H

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
	void showResult(QVector<QList<Player> > resultData);
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

    /*QGraphicsScene *scene;
    QTimer *timer;
    PlayerVisual *item;*/

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
    void onTableClicked(const QModelIndex &);


public slots:

};

class GridScene : public QGraphicsScene
{
public:
    GridScene(qreal x, qreal y, qreal w, qreal h)
        : QGraphicsScene(x, y, w, h)
    {

    }

    void drawBackground(QPainter *painter, const QRectF &rect);

};

#endif // DATAWINDOW_H
