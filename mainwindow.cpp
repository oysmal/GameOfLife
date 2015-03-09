#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "eventhandler.h"
#include "eventtest.h"
#include <QDebug>

#include <QGraphicsRectItem>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    grid = new Grid();
    grid->set_value_at(50,50, true);
    grid->set_value_at(0,50, true);
    grid->set_value_at(0,0, true);
    connect(ui->autoIterateButton, SIGNAL(clicked()), this, SLOT(sendEventTest()));
    QList<QRect> points;
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    loadGridIntoView();


}

MainWindow::~MainWindow()
{
    delete ui;
    delete grid;
}

void MainWindow::sendEventTest() {
    add_event_to_queue(Event::EVENT::AUTO_STEP);
    EventHandler::getInstance().notify_subscribers();
    qDebug() << EventTest::event_count << "\n";
}

void MainWindow::loadGridIntoView() {
    QPen pen (Qt::darkGreen);
    QBrush brush;
    brush.setColor( Qt::darkGreen );
    brush.setStyle( Qt::SolidPattern);

    qDebug() << "Loading grid into view...\n";
    int width = grid->get_size_x(), height = grid->get_size_y();
    for(int i = 0; i < width; i++) {
        for(int j = 0; j < height; j++) {
            if(grid->get_value_at(i, j) == true) {
                qDebug() << "Value at == true";
                QGraphicsRectItem *p = new QGraphicsRectItem(QRectF(width, height, 10, 10));
                points.append(p);
                scene->addItem(p);
            }
        }
    }
    ui->graphicsView->repaint();
}
