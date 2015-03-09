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
    grid = new Grid();
    grid->set_value_at(99,99, true);
    grid->set_value_at(0,99, true);
    grid->set_value_at(0,0, true);
    grid->set_value_at(1,1, true);
    grid->set_value_at(2,2, true);
    grid->set_value_at(3,3, true);
    grid->set_value_at(4,4, true);
    grid->set_value_at(5,5, true);
    grid->set_value_at(6,6, true);
    grid->set_value_at(7,7, true);
    grid->set_value_at(8,8, true);
    grid->set_value_at(9,9, true);
    grid->set_value_at(10,10, true);
    connect(ui->autoIterateButton, SIGNAL(clicked()), this, SLOT(sendEventTest()));
    QShortcut *shortcut = new QShortcut(QKeySequence(Qt::Key_Escape), this, SLOT(close()));
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
    add_event_to_queue(new Event(Event::EVENT::AUTO_STEP));
    EventHandler::getInstance().notify_subscribers();
    qDebug() << EventTest::event_count << "\n";
}

void MainWindow::loadGridIntoView() {
    QBrush *brush = new QBrush();
    brush->setColor( Qt::green );

    qDebug() << "Loading grid into view...\n";
    int width = grid->get_size_x(), height = grid->get_size_y();
    for(int i = 0; i < width; i++) {
        for(int j = 0; j < height; j++) {
            if(grid->get_value_at(i, j) == true) {
                qDebug() << "Value at == true";
                QPoint pos = scalePosition(i,j);
                scene->foregroundBrush().setColor(Qt::green);
                scene->foregroundBrush().setStyle(Qt::SolidPattern);
                QGraphicsRectItem *p = new QGraphicsRectItem(QRectF(pos.x(), pos.y(), 5, 5));
                p->setBrush(*brush);
                points.append(p);
                scene->addItem(p);
            }
        }
    }
}


QPoint MainWindow::scalePosition(int i, int j) {
    QSize size = ui->graphicsView->size();
    int width = grid->get_size_x();
    int height = grid->get_size_y();

    int widthfactor = size.width()/(float)width;
    int heightfactor = size.height()/(float)height;

    return QPoint(i*widthfactor, j*heightfactor);
}
