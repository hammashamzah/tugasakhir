#include "datalogger.h"

DataLogger::DataLogger()
{
	dataLog.clear();
}

DataLogger::~DataLogger() {

}


void DataLogger::add(QList<Player> newPlayer) {
	//find maximum id of newPlayer;
	if (!newPlayer.isEmpty()) {
		for (int newPlayerIterator = 0; newPlayerIterator < newPlayer.size(); newPlayerIterator++)
		{
			//check mathed id of newplayer to datalog
			int matchedIndex = -1;
			for (int i = 0; i < dataLog.size(); i++) {
				if (newPlayer.at(newPlayerIterator).id == dataLog.at(i).at(0).id) {
					matchedIndex = i;
				}
			}
			//qDebug() << "matched id: " << matchedIndex;
			if (matchedIndex == -1) {
				//new list on datalog
				QList<Player> newHistory;
				newHistory.append(newPlayer.at(newPlayerIterator));
				dataLog.append(newHistory);
			} else {
				dataLog[matchedIndex].append(newPlayer.at(newPlayerIterator));
			}
		}
		//qDebug() << "Data tidak kosong";
	} else {
		//qDebug() << "Data kosong";
	}
}
void DataLogger::saveToFile(QString filename) {
	QFile file(filename);
	if (file.open(QIODevice::WriteOnly)) {
		QTextStream stream(&file);

		for (int iter = 0; iter < dataLog.size(); iter++)
		{
			for (int historyIter = 0; historyIter < dataLog.at(iter).size(); historyIter++) {
				stream << dataLog.at(iter).at(historyIter).id << " "
				       << dataLog.at(iter).at(historyIter).camera << " "
				       << dataLog.at(iter).at(historyIter).framePosition << " "
				       << dataLog.at(iter).at(historyIter).pos.x << " "
				       << dataLog.at(iter).at(historyIter).pos.y << " "
				       << dataLog.at(iter).at(historyIter).speed.x << " "
				       << dataLog.at(iter).at(historyIter).speed.y << " "
				       << dataLog.at(iter).at(historyIter).acceleration.x << " "
				       << dataLog.at(iter).at(historyIter).acceleration.y << " "
				       << dataLog.at(iter).at(historyIter).cameraPos.x << " "
                       << dataLog.at(iter).at(historyIter).cameraPos.y << " \n";
			}
		}
	}
	file.close();
}

void DataLogger::loadFromFile(QString filename) {
	filename = "data.log";
	QFile file(filename);
	if (file.open(QIODevice::ReadOnly)) {
		dataLog.clear();
		QStringList lines = QString(file.readAll()).split(QRegExp("[\r\n]"));
		foreach (QString line, lines) {
			Player temp(line.section(" ", 0, 0).toInt(), //id
			            line.section(" ", 1, 1).toInt(), //camera
			            line.section(" ", 2, 2).toInt(), //framePosition
                        Point2f(line.section(" ", 3, 3).toFloat(), line.section(" ", 4, 4).toFloat()), //pos
                        Point2f(line.section(" ", 5, 5).toFloat(), line.section(" ", 6, 6).toFloat()), //speed
                        Point2f(line.section(" ", 7, 7).toFloat(), line.section(" ", 8, 8).toFloat()), //acceleration
                        Point2f(line.section(" ", 9, 9).toFloat(), line.section(" ", 10, 10).toFloat())); //cameraPos
			int currentId = -1;
			for (int i = 0; i < dataLog.size(); i++) {
				if (temp.id == dataLog.at(i).at(0).id) {
					currentId = i;
				}
			}
			qDebug() << "current id: " << currentId;
			if (currentId == -1) {
				QList<Player> newHistory;
				newHistory.append(temp);
				dataLog.append(newHistory);
			} else {
				dataLog[currentId].append(temp);
			}
		}
	}
}
