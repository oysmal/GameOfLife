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
    std::shared_ptr<QAction> closeAction = std::shared_ptr<QAction>(new QAction(this));
    std::shared_ptr<QShortcut> escapeShortcut = std::shared_ptr<QShortcut>(new QShortcut(this));
    escapeShortcut->setKey(QKeySequence(Qt::Key_Escape));
    closeAction->setShortcut(QKeySequence(Qt::Key_Escape));
    connect(closeAction.get(), SIGNAL(activated()), this, SLOT(close()));

    scene = std::shared_ptr<QGraphicsScene>(new QGraphicsScene(this));
    ui->graphicsView->setScene(scene.get());

    loadGridIntoView();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::sendEventTest() {
    add_event_to_queue(std::shared_ptr<Event>(new Event(Event::EVENT::AUTO_STEP)));
    EventHandler::getInstance().notify_subscribers();
    qDebug() << EventTest::event_count << "\n";
}

void MainWindow::loadGridIntoView() {
    std::shared_ptr<QBrush> brush = std::shared_ptr<QBrush>(new QBrush());
    brush->setColor( Qt::green );

    qDebug() << "Loading grid into view...\n";
    int width = Grid::getInstance().get_size_x(), height = Grid::getInstance().get_size_y();
    for(int i = 0; i < width; i++) {
        for(int j = 0; j < height; j++) {
            if(Grid::getInstance().get_value_at(i, j) == true) {
                qDebug() << "Value at == true";
                QPoint pos = scalePosition(i,j);
                scene->foregroundBrush().setColor(Qt::green);
                scene->foregroundBrush().setStyle(Qt::SolidPattern);
                std::shared_ptr<QGraphicsRectItem> p = std::shared_ptr<QGraphicsRectItem>(new QGraphicsRectItem(QRectF(pos.x(), pos.y(), 5, 5)));
                p->setBrush(*brush.get());
                points.append(p);
                scene->addItem(p.get());
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
