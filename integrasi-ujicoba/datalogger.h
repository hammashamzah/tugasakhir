#ifndef DATALOGGER_H
#define DATALOGGER_H

#include <player.h>
#include <QList>
#include <QString>
#include <QStringList>
#include <QFileDialog>
#include <QTextStream>
#include <QObject>
#include <QDebug>
#include "datalogger.h"
#include <iostream>

class DataLogger : public QObject
{	Q_OBJECT
public:
	DataLogger();
	~DataLogger();
	QList<QList<Player> > dataLog;
	void saveToFile(QString filename);
	void loadFromFile(QString filename);
	DataLogger *myDataLogger;
public slots:
	void add(QList<Player> newPlayer);
private:
	QString filename;

};

#endif // DATALOGGER_H
