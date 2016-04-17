#ifndef DATALOGGER_H
#define DATALOGGER_H

#include <player.h>
#include <QList>
#include <QString>
#include <QStringList>
#include <QFileDialog>
#include <QTextStream>
#include <QObject>
#include <iostream>

class DataLogger : public QObject
{	Q_OBJECT
public:
	DataLogger();
	~DataLogger();
	QList<QList<Player> > dataLog;
	void saveToFile();
	void loadFromFile();
public slot:
	void add(QList<Player> newPlayer);
private:
	QString filename;

};

#endif // DATALOGGER_H
