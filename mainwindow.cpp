#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QShortcut>
#include <QGraphicsRectItem>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    qDebug() << "Setting up ui";
    ui->setupUi(this);
    Grid::getInstance().set_value_at(99,99, true);
    Grid::getInstance().set_value_at(0,99, true);
    Grid::getInstance().set_value_at(99,0, true);
    Grid::getInstance().set_value_at(1,0, true);
    Grid::getInstance().set_value_at(2,1, true);
    Grid::getInstance().set_value_at(2,2, true);
    Grid::getInstance().set_value_at(1,2, true);
    Grid::getInstance().set_value_at(0,2, true);

    qDebug() <<"before slots";
    this->connect(ui->runButton, SIGNAL(clicked()), this, SLOT(startGame()));
    this->connect(ui->nextStepButton, SIGNAL(clicked()), this, SLOT(iterateGame()));
    this->connect(ui->stopButton, SIGNAL(clicked()), this, SLOT(stopGame()));

    qDebug() <<"before scene";
    scene = std::shared_ptr<QGraphicsScene>(new QGraphicsScene(this));
    ui->graphicsView->setScene(scene.get());

    qDebug() <<"before load into view";
    loadGridIntoView();

}

MainWindow::~MainWindow()
{
    delete ui;
    scene.reset();
}

void MainWindow::loadGridIntoView() {

    scene->clear();

    qDebug() << "Loading grid into view...\n";
    int width = Grid::getInstance().get_size_x(), height = Grid::getInstance().get_size_y();
    for(int i = 0; i < width; i++) {
        for(int j = 0; j < height; j++) {
            if(Grid::getInstance().get_value_at(i, j) == true) {
                QPoint pos = scalePosition(i,j);
                QGraphicsRectItem *p = new QGraphicsRectItem(QRectF(pos.x(), pos.y(), 5, 5));
                QBrush *q = new QBrush(Qt::black);
                p->setBrush(*q);
                scene->addItem(p);
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
    continueLoop = true;
}

void MainWindow::iterateGame() {
    game.iterate();
    loadGridIntoView();
}

void MainWindow::stopGame() {
    continueLoop = false;
}

void MainWindow::loop() {

}
