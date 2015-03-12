#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "eventhandler.h"
#include "eventtest.h"
#include <QDebug>
#include <QShortcut>

#include <QGraphicsRectItem>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Grid::getInstance().set_value_at(99,99, true);
    Grid::getInstance().set_value_at(0,99, true);
    Grid::getInstance().set_value_at(99,0, true);
    Grid::getInstance().set_value_at(0,0, true);
    Grid::getInstance().set_value_at(1,1, true);
    Grid::getInstance().set_value_at(2,2, true);
    Grid::getInstance().set_value_at(3,3, true);
    Grid::getInstance().set_value_at(4,4, true);
    Grid::getInstance().set_value_at(5,5, true);
    Grid::getInstance().set_value_at(6,6, true);
    Grid::getInstance().set_value_at(7,7, true);
    Grid::getInstance().set_value_at(8,8, true);
    Grid::getInstance().set_value_at(9,9, true);
    Grid::getInstance().set_value_at(10,10, true);

    connect(ui->autoIterateButton, SIGNAL(clicked()), this, SLOT(sendEventTest()));

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    loadGridIntoView();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::sendEventTest() {
    add_event_to_queue(std::shared_ptr<gol::Event>(new gol::Event(gol::Event::EVENT::AUTO_STEP)));
    EventHandler::getInstance().notify_subscribers();
    qDebug() << EventTest::event_count << "\n";
}

void MainWindow::loadGridIntoView() {

    qDebug() << "Loading grid into view...\n";
    int width = Grid::getInstance().get_size_x(), height = Grid::getInstance().get_size_y();
    for(int i = 0; i < width; i++) {
        for(int j = 0; j < height; j++) {
            if(Grid::getInstance().get_value_at(i, j) == true) {
                QPoint pos = scalePosition(i,j);
                QGraphicsRectItem *p = new QGraphicsRectItem(QRectF(pos.x(), pos.y(), 5, 5));
                points.append(p);
                scene->addItem(p);
            }
        }
    }
}


QPoint MainWindow::scalePosition(int i, int j) {
    QSize size = ui->graphicsView->size();
    int width = Grid::getInstance().get_size_x();
    int height = Grid::getInstance().get_size_y();

    int widthfactor = size.width()/(float)width;
    int heightfactor = size.height()/(float)height;

    return QPoint(i*widthfactor, j*heightfactor);
}
