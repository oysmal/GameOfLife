#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "eventhandler.h"
#include "eventtest.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->autoIterateButton, SIGNAL(clicked()), this, SLOT(sendEventTest()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::sendEventTest() {
    add_event_to_queue(Event::EVENT::AUTO_STEP);
    EventHandler::getInstance().notify_subscribers();
    qDebug() << EventTest::event_count << "\n";
}
