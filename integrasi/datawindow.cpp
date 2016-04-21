#include "datawindow.h"
#include "ui_datawindow.h"
#include <QMessageBox>

DataWindow::DataWindow(QWidget *parent) :
QWidget(parent),
ui(new Ui::DataWindow)
{
    ui->setupUi(this);
    //connect signal and SLOT
    connect(ui->tableView_result, SIGNAL(activated(const QModelIndex &)), this, SLOT(onTableClicked(const QModelIndex &)));

    //set configuration
    ui->pushButton_load->setEnabled(false);
    ui->pushButton_save->setEnabled(false);

    //construct model to used
    model =new QStandardItemModel();

    tempPlayersData=setRandomQList();
    showResult(tempPlayersData);
    ui->tableView_result->Begin(model);
}

DataWindow::~DataWindow()
{
    delete ui;
}

void DataWindow::PlayBack()
{
    /*scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    scene->setSceneRect(-200,-200,300,300);

    QPen mypen = QPen(Qt::red);

    QLineF TopLine(scene->sceneRect().topLeft(), scene->sceneRect().topRight());
    QLineF LeftLine(scene->sceneRect().topLeft(), scene->sceneRect().bottomLeft());
    QLineF RightLine(scene->sceneRect().topRight(), scene->sceneRect().bottomRight());
    QLineF BottomLine(scene->sceneRect().bottomLeft(), scene->sceneRect().bottomRight());

    scene->addLine(TopLine,mypen);
    scene->addLine(RightLine,mypen);
    scene->addLine(LeftLine,mypen);
    scene->addLine(BottomLine,mypen);

    int ItemCount = 25;

    for(int i = 0; i < ItemCount; i++)
    {
        PlayerVisual *a = new PlayerVisual();
        scene->addItem(a);
    }

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), scene,SLOT(advance()));
    timer->start(10);    */
}

void DataWindow::getItemSelected()
{
    idSelected = ui->tableView_result->getIndexesSelected().at(0).row();
    frameSelected.clear();
    for(int i=0;i<ui->tableView_result->getIndexesSelected().size();i++)
    {
        frameSelected.append(ui->tableView_result->getIndexesSelected().at(i).column());
    }

}

void DataWindow::showResult(QVector<QList<Player> > resultData)
{
    QStandardItem *newItem = 0;

    model->clear();
    QList<QString> labels;
    for(int frame=0;frame<54000;frame++)
    {
        if (frame==0) labels.append("ID");
        else labels.append("Frame"+QString::number(frame));
    }
    model->setHorizontalHeaderLabels(labels);
    for (int id = 0; id < resultData.size(); ++id)
    {
        for (int rec = 0; rec < resultData.at(id).size(); ++rec)
        {
            if (rec==0) newItem = new QStandardItem(QString::number(id));
            else newItem = new QStandardItem(QString::number(1));
            switch (id) {
            case 0:
                newItem->setBackground(QBrush(QColor(Qt::blue)));
                break;
            case 1:
                newItem->setBackground(QBrush(QColor(Qt::red)));
                break;
            case 2:
                newItem->setBackground(QBrush(QColor(Qt::yellow)));
                break;
            case 3:
                newItem->setBackground(QBrush(QColor(Qt::cyan)));
                break;
            case 4:
                newItem->setBackground(QBrush(QColor(Qt::magenta)));
                break;
            case 5:
                newItem->setBackground(QBrush(QColor(Qt::gray)));
                break;
            case 6:
                newItem->setBackground(QBrush(QColor(Qt::green)));
                break;
            case 7:
                newItem->setBackground(QBrush(QColor(Qt::darkBlue)));
                break;
            case 8:
                newItem->setBackground(QBrush(QColor(Qt::darkCyan)));
                break;
            case 9:
                newItem->setBackground(QBrush(QColor(Qt::darkGray)));
                break;
            case 10:
                newItem->setBackground(QBrush(QColor(Qt::darkGreen)));
                break;
            case 11:
                newItem->setBackground(QBrush(QColor(Qt::darkMagenta)));
                break;
            case 12:
                newItem->setBackground(QBrush(QColor(Qt::darkRed)));
                break;
            case 13:
                newItem->setBackground(QBrush(QColor(Qt::darkYellow)));
                break;

            default:
                break;
            }

            model->setItem(id, resultData.at(id).at(rec).framePosition, newItem);
        }
    }
}

void DataWindow::on_pushButton_display_data_released()
{

}

void DataWindow::on_pushButton_load_released()
{
    filename = QFileDialog::getOpenFileName(this,
        tr("Open Log File"), ".",
        tr("Log File (*.log)"));
    myDataLogger.saveToFile(filename);
}

void DataWindow::on_pushButton_save_released()
{
    filename = QFileDialog::getSaveFileName(this, tr("Save Masking Coordinate File"), "maskingcoordinate.txt",
        tr("Masking Coordinate File (*.txt)"));
    myDataLogger.loadFromFile(filename);

}

void DataWindow::addData(QList<Player> newData){
    myDataLogger.add(newData);
}

void DataWindow::dataEntryFinished(){
    ui->pushButton_load->setEnabled(true);
    ui->pushButton_save->setEnabled(true);
}

void DataWindow::on_pushButton_cut_clicked()
{
    tempSinglePlayerRec.clear();
    getItemSelected();
    qDebug()<<idSelected;
    qDebug()<<frameSelected;

    //copy selected to temp and then remove it
    for(int i=0;i<frameSelected.size();i++)
    {
        //update model
        model->setItem(idSelected,frameSelected.at(i), new QStandardItem(QString::null));
        //looking for frame number in QList Rec of Player and copy that
        for(int j=0;j<tempPlayersData.at(idSelected).size();j++)
        {
            if(tempPlayersData.at(idSelected).at(j).framePosition==frameSelected.at(i))
            {
                tempSinglePlayerRec.append(tempPlayersData.at(idSelected).at(j));
                tempPlayersData[idSelected].removeAt(j);
            }
        }
    }
}

void DataWindow::on_pushButton_paste_clicked()
{
    getItemSelected();
    tempPlayersData[idSelected].append(tempSinglePlayerRec);
    showResult(tempPlayersData);
}

void DataWindow::on_pushButton_refresh_clicked()
{
    showResult(tempPlayersData);
    ui->tableView_result->Begin(model);
}

void DataWindow::onTableClicked(const QModelIndex &index)
{
    if (index.isValid()) {
        qDebug()<< index.row()<<" "<<index.column()<<" "<<index.data().toString();
    }
}

QVector<QList<Player> > DataWindow::setRandomQList()
{
    QVector<QList<Player> > playerData;
    playerData.resize(20);
    Player playerUnit;

    for (int i = 0; i < 20; ++i)
    {
        for (int j = 0; j < 20; ++j)
        {
            playerUnit.id = i;
            playerUnit.framePosition = j;
            playerData[i].append(playerUnit);
        }
    }
    return playerData;
}
