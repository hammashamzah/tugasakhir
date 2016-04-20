#include "datawindow.h"
#include "ui_datawindow.h"
#include <QMessageBox>

DataWindow::DataWindow(QWidget *parent) :
QWidget(parent),
ui(new Ui::DataWindow)
{
    ui->setupUi(this);

    connect(ui->tableView_result, SIGNAL(activated(const QModelIndex &)), this, SLOT(onTableClicked(const QModelIndex &)));

    ui->pushButton_load->setEnabled(false);
    ui->pushButton_save->setEnabled(false);
    model =new QStandardItemModel();
    showResult(this->setRandomQList());
    ui->tableView_result->Begin(model);
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

void DataWindow::showResult(QVector<QList<Player> > resultData)
{
/*    QFile file("grades.txt");
    if (file.open(QFile::ReadOnly)) {
        QString line = file.readLine(200);
        QStringList list = line.simplified().split(",");
        model->setHorizontalHeaderLabels(list);

        int row = 0;
        QStandardItem *newItem = 0;
        while (file.canReadLine()) {
            line = file.readLine(200);
            if (!line.startsWith("#") && line.contains(",")) {
                list= line.simplified().split(",");
                for (int col = 0; col < list.length(); ++col){
                    newItem = new QStandardItem(list.at(col));
                    model->setItem(row, col, newItem);
                }
                ++row;
            }
        }
    }
    file.close();*/

    QStandardItem *newItem = 0;


    for (int id = 0; id < resultData.size(); ++id)
    {
        for (int rec = 0; rec < resultData.at(id).size(); ++rec)
        {
            newItem = new QStandardItem(QString::number(1));
            newItem->setDragEnabled(true);
            newItem->setDropEnabled(true);            
            model->setItem(id, rec, newItem);
        }
    }
    /*QPen mypen(Qt::blue);
    mypen.setWidth(5);
    //painter.setPen(Qt::blue);
    QGraphicsScene *scene=new QGraphicsScene(0, 0, 20000, 20000);
    for(int j=1;j<=500;j++)
    {
        QGraphicsTextItem *textItem = new QGraphicsTextItem;

        textItem->setPlainText(QString::number(j));
        textItem->setPos(20,25*j-10);
        scene->addItem(textItem);
        for(int i=1;i<500;i++)
        {
    QPainter painter(this);
            QGraphicsLineItem *lineItem = new QGraphicsLineItem;
            lineItem->setLine(50+20*i, 25*j, 50+20*i+5, 25*j);
            lineItem->setPen(mypen);
            scene->addItem(lineItem);
        }
    }

    ui->graphicsView->setScene(scene);
    */
}
DataWindow::~DataWindow()
{
    delete ui;
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

void GridScene::drawBackground(QPainter *painter, const QRectF &rect)
{
    const int gridSize = 25;

    qreal left = int(rect.left()) - (int(rect.left()) % gridSize);
    qreal top = int(rect.top()) - (int(rect.top()) % gridSize);

    QVarLengthArray<QLineF, 100> lines;

    for (qreal x = left; x < rect.right(); x += gridSize)
        lines.append(QLineF(x, rect.top(), x, rect.bottom()));
    for (qreal y = top; y < rect.bottom(); y += gridSize)
        lines.append(QLineF(rect.left(), y, rect.right(), y));

    //qDebug() << lines.size();

    painter->drawLines(lines.data(), lines.size());
}

void DataWindow::on_pushButton_cut_clicked()
{
    tempPlayerRec.clear();
    for (int frame = ui->tableView_result->getIndexesSelected().; frame < ui->tableView_result->getIndexesSelected().size(); ++frame)
    {
       model->setData(ui->tableView_result->getIndexesSelected().at(i),QString::number(0));
       
    }
}

void DataWindow::on_pushButton_paste_clicked()
{

}

void DataWindow::on_pushButton_refresh_clicked()
{
    showResult(this->setRandomQList());
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
    playerData.resize(100);
    Player playerUnit;

    for (int i = 0; i < 100; ++i)
    {
        for (int j = 0; j < 100; ++j)
        {
            playerUnit.id = i;
            playerUnit.framePosition = j;
            playerData[i].append(playerUnit);
        }
    }
    return playerData;
}
