#include "datalogger.h"

DataLogger::DataLogger()
{
dataLog.clear();
}

DataLogger::~DataLogger(){

}


void DataLogger::add(QList<Player> newPlayer) {
	//find maximum id of newPlayer;
	for (int newPlayerIterator = 0; newPlayerIterator < newPlayer.size(); newPlayerIterator++)
	{
		//check mathed id of newplayer to datalog
		int matchedId = -1;
		for(int i = 0; i < dataLog.size(); i++){
			if(newPlayer.at(newPlayerIterator).id == dataLog.at(i).at(0).id){
                matchedId = dataLog.at(i).at(0).id;
			}
		}
		if(matchedId == -1){
			//new list on datalog
			QList<Player> newHistory;
			newHistory.append(newPlayer);
			dataLog.append(newHistory);
		}else{
			dataLog[matchedId].append(newPlayer.at(newPlayerIterator));
		}
		if (newPlayer.at(newPlayerIterator).id > (dataLog.size() - 1)) {
			//new id
			
		} else {
			//append to last id
            
		}
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
                       << dataLog.at(iter).at(historyIter).cameraPos.y << " " " \n";
			}
		}
	}
	file.close();
}

void DataLogger::loadFromFile(QString filename) {
    filename = "match.log";
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
                        Point2f(line.section(" ",8,8).toInt(),line.section(" ",9,9).toInt()), //acceleration
                        Point2f(line.section(" ",10, 10).toInt(), line.section(" ", 11,11).toInt())); //cameraPos
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
