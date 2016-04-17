#include "datalogger.h"

DataLogger::DataLogger()
{

}

DataLogger::~DataLogger(){

}


void DataLogger::add(QList<Player> newPlayer) {
	//find maximum id of newPlayer;
	for (int newPlayerIterator = 0; newPlayerIterator < newPlayer.size(); newPlayerIterator++)
	{
		if (newPlayer.at(newPlayerIterator).id > (dataLog.size() - 1)) {
			//new id
			QList<Player> newHistory;
			newHistory.append(newPlayer);
			dataLog.append(newHistory);
		} else {
			//append to last id
            dataLog[newPlayer.at(newPlayerIterator).id].append(newPlayer.at(newPlayerIterator));
		}
	}
}
void DataLogger::saveToFile() {
    filename = "match.log";
    //file dialog dipanggil di window yang bersesuaian
    //filename = QFileDialog::getSaveFileName(this, tr("Save Log File"), "Match Log.log",
    //                                        tr("Log File (*.log)"));
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
				       << dataLog.at(iter).at(historyIter).transformedPos.x << " "
				       << dataLog.at(iter).at(historyIter).transformedPos.y << " "
				       << dataLog.at(iter).at(historyIter).transformedSpeed.x << " "
				       << dataLog.at(iter).at(historyIter).transformedSpeed.y << " \n";
			}
		}
	}
	file.close();
}

void DataLogger::loadFromFile() {
    filename = "match.log";
    //filename = QFileDialog::getOpenFileName(this,
    //                                        tr("Open Log File"), ".",
    //                                        tr("Log File (*.log)"));
	QFile file(filename);
	if (file.open(QIODevice::ReadOnly)) {
		dataLog.clear();
		QStringList lines = QString(file.readAll()).split(QRegExp("[\r\n]"));
		int currentId = 0;
		foreach(QString line, lines){
			Player temp(line.section(" ",0,0).toInt(), //id
						line.section(" ",1,1).toInt(), //camera
						line.section(" ",2,2).toInt(), //framePosition
						Point2f(line.section(" ",4,4).toInt(),line.section(" ",5,5).toInt()), //pos
						Point2f(line.section(" ",6,6).toInt(),line.section(" ",7,7).toInt()), //speed
						Point2f(line.section(" ",8,8).toInt(),line.section(" ",9,9).toInt()), //transformedPos
						Point2f(line.section(" ",10,10).toInt(),line.section(" ",11,11).toInt())); //transformedSpeed
			if(temp.id == currentId){
                dataLog[currentId].append(temp);
			}else{
				currentId = temp.id;
				QList<Player> newHistory;
				newHistory.append(temp);
				dataLog.append(newHistory);
			}
		}
	}
}