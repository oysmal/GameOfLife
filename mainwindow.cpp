#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "eventhandler.h"
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
    Grid::getInstance().set_value_at(1,2, true);
    Grid::getInstance().set_value_at(1,3, true);
    Grid::getInstance().set_value_at(1,4, true);
    Grid::getInstance().set_value_at(2,1, true);
    Grid::getInstance().set_value_at(3,1, true);
    Grid::getInstance().set_value_at(4,1, true);
    Grid::getInstance().set_value_at(2,3, true);
    Grid::getInstance().set_value_at(2,2, true);
    Grid::getInstance().set_value_at(3,3, true);
    Grid::getInstance().set_value_at(4,4, true);
    Grid::getInstance().set_value_at(5,5, true);
    Grid::getInstance().set_value_at(6,6, true);
    Grid::getInstance().set_value_at(7,7, true);
    Grid::getInstance().set_value_at(8,8, true);
    Grid::getInstance().set_value_at(9,9, true);
    Grid::getInstance().set_value_at(10,10, true);

    this->connect(ui->runButton, SIGNAL(clicked()), this, SLOT(startGame()));
    this->connect(ui->manualIterateButton, SIGNAL(clicked()), this, SLOT(iterateGame()));

    scene = std::shared_ptr<QGraphicsScene>(new QGraphicsScene(this));
    ui->graphicsView->setScene(scene.get());

    loadGridIntoView();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadGridIntoView() {

    scene->clear();

    qDebug() << "Loading grid into view...\n";
    int width = Grid::getInstance().get_size_x(), height = Grid::getInstance().get_size_y();
    for(int i = 0; i < width; i++) {
        for(int j = 0; j < height; j++) {
            if(Grid::getInstance().get_value_at(i, j) == true) {
                QPoint pos = scalePosition(i,j);
                std::shared_ptr<QGraphicsRectItem> p = std::shared_ptr<QGraphicsRectItem>(new QGraphicsRectItem(QRectF(pos.x(), pos.y(), 5, 5)));
                points.append(p);
                p->setBrush(QBrush(Qt::black));
                scene->addItem(p.get());
            }
        }
    }
}


// Scale the point position from grid coordinates to the graphicsview coordiantes.
QPoint MainWindow::scalePosition(int i, int j) {
    QSize size = ui->graphicsView->size();
    int width = Grid::getInstance().get_size_x();
    int height = Grid::getInstance().get_size_y();

    int widthfactor = size.width()/(float)width;
    int heightfactor = size.height()/(float)height;

    return QPoint(i*widthfactor, j*heightfactor);
}



void MainWindow::startGame() {
    this->game;
    this->game.iterator_step(1);
    loadGridIntoView();
}

void MainWindow::iterateGame() {
    this->game.iterator_step(1);
    loadGridIntoView();
}
